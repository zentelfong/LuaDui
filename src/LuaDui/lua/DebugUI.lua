local Window=UI.CWindowUI
local Debug={}

local _window=nil

function print(text,...)
	if _window then
		local edit= _window:findControl("textOutPut")
		if type(text)=="string" then
			edit:appendText(string.format(text,...))
		else
			edit:appendText(tostring(text))
		end
	end
end



function println(text,...)
	if _window then
		local edit= _window:findControl("textOutPut")
		edit:appendText(string.format(text,...))
		edit:appendText("\n")
	end
end


function Debug.showDebugUI()
	local wndCfg={
		res="DebugUI.xml",
		name="DebugWnd",
		title="调试",
		type="popup",
		w=800,
		h=600
	}
	if not _window then
		_window=Window.create(wndCfg)
		_window:centerWindow()
	end
	
end


function Debug.setTitle(title)
	local wnd=_window
	if wnd then
		local label=wnd:findControl("标题")
		label:setText(title)
		wnd:setWindowText(title)
	end	
end


function var_dump(data, max_level, prefix)
    if type(prefix) ~= "string" then
        prefix = ""
    end
    if type(data) ~= "table" then
        println(prefix .. tostring(data))
    else
        println(tostring(data))
        if max_level ~= 0 then
            local prefix_next = prefix .. "    "
            println(prefix .. "{")
            for k,v in pairs(data) do
                print(prefix_next .. k .. " = ")
                if type(v) ~= "table" or (type(max_level) == "number" and max_level <= 1) then
                    println(v)
                else
                    if max_level == nil then
                        var_dump(v, nil, prefix_next)
                    else
                        var_dump(v, max_level - 1, prefix_next)
                    end
                end
            end
            println(prefix .. "}")
        end
    end
end



return Debug