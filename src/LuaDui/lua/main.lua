
local app=UI.CApplicationUI.sharedInstance()

app:setResourcePath(app:instancePath().."skin")





print("start")
local Window=UI.CWindowUI

local wnd=Window.create({res="skin.xml",name="TestWindow",x=0,y=0,w=800,h=600})

local builder=wnd:createBuilder()
builder:loadFile("ComputerExamine.xml")

wnd:findControl("switch"):addAt(builder:buildControl(),0)



print("dsadsadsadsadsad")
print(wnd)

wnd:centerWindow()














