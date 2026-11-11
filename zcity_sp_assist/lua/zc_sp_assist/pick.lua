-- Pure target-selection math. Only needs Vector arithmetic (sub, Dot, Length),
-- so it can be checked outside the game with a stub Vector.
-- Units: Source units, angles in degrees. FOV is the full angle between the
-- bullet direction and the direction to the target point (a cone half-angle).

local Pick = {}

local function IsFinite(n)
	return n == n and n ~= math.huge and n ~= -math.huge
end

-- Angle in degrees between unit vector dir and the ray src -> point.
-- Returns nil when the point coincides with src or the input is not finite.
function Pick.AngleTo(src, dir, point)
	local to = point - src
	local len = to:Length()
	if not IsFinite(len) or len < 1e-3 then return nil end

	local cos = dir:Dot(to) / len
	if not IsFinite(cos) then return nil end
	if cos > 1 then cos = 1 elseif cos < -1 then cos = -1 end

	return math.deg(math.acos(cos)), len
end

-- points: array of { pos = Vector, ... }. Returns a new array of the entries
-- inside the cone, nearest angle first, each with .angle and .dist filled in.
function Pick.WithinFov(src, dir, points, fovDeg)
	local out = {}

	for i = 1, #points do
		local entry = points[i]
		local angle, dist = Pick.AngleTo(src, dir, entry.pos)

		if angle and angle <= fovDeg then
			entry.angle = angle
			entry.dist = dist
			out[#out + 1] = entry
		end
	end

	table.sort(out, function(a, b)
		if a.angle ~= b.angle then return a.angle < b.angle end
		return a.dist < b.dist
	end)

	return out
end

return Pick
