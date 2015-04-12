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

return Debug