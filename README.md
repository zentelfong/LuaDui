LuaDui
======

LuaDui 0.9 version

LuaDui是duilib的lua扩展，使用LuaDui库你可以使用lua脚本来处理所有的界面逻辑，当业务逻辑或需求变化时通过修改lua脚本很容易满足需求，达到界面和业务逻辑的分离，LuaDui可以根据业务需求引入其他第三方库来使用如：lsqlite,luasocket等提高开发效率。

LuaDui库使用luajit2.0脚本引擎，高效而稳定。

LuaDui使用pugixml替换了duilib自带的xml解析器，提高了创建控件时xml解析效率。

LuaDui使用C++库LuaObj导出duilib接口到lua环境中，你也可以根据需求导出你的特定接口给lua环境。

LuaDui提供可供输入以及接受lua脚本进行运行的调试界面，使得开发调试更便捷。

LuaDui可以使用zbstudio编辑lua脚本，支持lua脚本高亮显示，支持LuaDui库接口自动补全功能，支持lua脚本的端点调试功能。

HelloWorld
======
main.lua中

```lua
local wnd=UI.CWindowUI.create({res="helloWorld.xml",name="HelloWorld"})
wnd:centerWindow()
wnd:showWindow(true,true)
```

helloWorld.xml中

```xml
<?xml version="1.0" encoding="UTF-8"?>
<Window caption="0,0,0,30" size="600,480">
<VerticalLayout bkcolor="#ff019bd0" inset="1,1,1,1" bordersize="1" bordercolor="#FF010000">
    <HorizontalLayout height="30">
    	<Control/>
        <Button name="closebtn" width="47" height="22" text="Close" bkcolor="#ffef2f4d">
			<Event>
				<click>
					this:window():close()
				</click>
			</Event>
		</Button>
    </HorizontalLayout>
	<Text text="Hello World!" align="center"/>
</VerticalLayout>
</Window>
```