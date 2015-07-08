--require ("debug.mobdebug").start()

local debug=require ("DebugUI")

local app=UI.CApplicationUI.sharedInstance()

app:setResourcePath(app:instancePath().."skin")

debug.showDebugUI()



local Window=UI.CWindowUI

app:setResourceZip("360Demo.zip")
local wnd=Window.create({res="skin.xml",name="360Demo",x=0,y=0,w=800,h=600})
wnd:centerWindow()






--require ("luv")







