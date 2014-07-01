UseAbsolute = false		--是否使用绝对时间
AbsoluteTime = "2009-12-19 20:01"
RelativeTime = "00:01:00"

if(UseAbsolute) then
	Year = tonumber(string.sub(AbsoluteTime, 1, 4))
	Month = tonumber(string.sub(AbsoluteTime, 6, 7))
	Day = tonumber(string.sub(AbsoluteTime, 9, 10))
	Hour = tonumber(string.sub(AbsoluteTime, 12, 13))
	Minute = tonumber(string.sub(AbsoluteTime, 15, 16))
else
	local hour = tonumber(string.sub(RelativeTime, 1, 2))
	local minute = tonumber(string.sub(RelativeTime, 4, 5))
	local second = tonumber(string.sub(RelativeTime, 7, 8))
	Seconds = (hour*60+minute)*60 + second
end

Commands =
{
--  切换到节能模式
--	"powercfg -S a1841308-3541-4fab-bc81-f71556f20b4a",
	"C:\\windows\\notepad.exe",
--	"G:\\Program Files\\easyMule\\emule.exe",
}

--以下为自动睡眠
AutoSleep = true	--是否启用自动睡眠
SleepAction = 1		--1:Sleep 2:Hibernate

SUseAbsolute = true		--是否使用绝对时间
SAbsoluteTime = "2009-12-20 11:28"
SRelativeTime = "00:00:30"

if(SUseAbsolute) then
	SYear = tonumber(string.sub(SAbsoluteTime, 1, 4))
	SMonth = tonumber(string.sub(SAbsoluteTime, 6, 7))
	SDay = tonumber(string.sub(SAbsoluteTime, 9, 10))
	SHour = tonumber(string.sub(SAbsoluteTime, 12, 13))
	SMinute = tonumber(string.sub(SAbsoluteTime, 15, 16))
else
	local hour = tonumber(string.sub(SRelativeTime, 1, 2))
	local minute = tonumber(string.sub(SRelativeTime, 4, 5))
	local second = tonumber(string.sub(SRelativeTime, 7, 8))
	SSeconds = (hour*60+minute)*60 + second
end