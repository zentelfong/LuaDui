
local app=UI.CApplicationUI.sharedInstance()

app:setResourcePath(app:instancePath().."skin")





print("start")
local Window=UI.CWindowUI

local wnd=Window.create({res="test1.xml",name="TestWindow",x=0,y=0,w=800,h=600})

print("dsadsadsadsadsad")
print(wnd)

wnd:centerWindow()














