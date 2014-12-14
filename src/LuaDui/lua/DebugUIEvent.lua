local function minBtnClick(btn)
	btn:window():showMin()
end

local function closeBtnClick(btn)
	btn:window():close()
	UI.CApplicationUI.sharedInstance():quit()
end




local function run(btn)
	local text=btn:window():findControl("input"):text()
	local rs,err=pcall(load(text))
	if not rs then
		print(err)
	end
end

local function clear(btn)
	local edit= btn:window():findControl("textOutPut")
	edit:setText("")
end


local events={
minBtnClick=minBtnClick,
closeBtnClick=closeBtnClick,
run=run,
clear=clear
}

return events