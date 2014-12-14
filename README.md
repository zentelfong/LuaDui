LuaDui
======

LuaDui 0.9 version

LuaDui是duilib的lua扩展，使用LuaDui库你可以使用lua脚本来处理所有的界面逻辑，当业务逻辑或需求变化时通过修改lua脚本很容易满足需求，达到界面和业务逻辑的分离，LuaDui可以根据业务需求引入其他第三方库来使用如：lsqlite,luasocket等提高开发效率。

LuaDui库使用luajit2.0脚本引擎，高效稳定快捷。

LuaDui使用rapidxml替换了duilib自带的xml解析器，提高了创建控件时xml解析效率。

LuaDui使用C++库LuaObj导出duilib接口到lua环境中方便快捷，你也可以根据需求导出你的特定接口给lua环境。
