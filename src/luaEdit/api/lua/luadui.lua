
local UI={
 childs={
  CWindowUI={
	childs={
		

	},
	description = "窗口类，窗口相关的操作。",
	type = "class"  
  },
  
  CControlUI={
	childs={
		window={
		  type="function",
		  description="获取窗口",
		  args="(nil)",
		  returns = "CWindowUI"
		},
		windowHandle={
		  type="function",
		  description="获取窗口句柄",
		  args="(nil)",
		  returns = "(handle:number)"
		},	
		text={
		  type="function",
		  description="获取文本",
		  args="(nil)",
		  returns = "(text:string)"
		},
		setText={
		  type="function",
		  description="设置文本",
		  args="(text:string)",
		  returns = "(nil)"
		},		
		activate={
		  type="function",
		  description="激活控件",
		  args="(nil)",
		  returns = "(nil)"
		},
		parent={
		  type="function",
		  description="获取父控件",
		  args="(nil)",
		  returns = "(parent:CControlUI)"
		},
		name={
		  type="function",
		  description="获取控件名",
		  args="(nil)",
		  returns = "(control:CControlUI)"
		},
		
		setName={
		  type="function",
		  description="设置控件名",
		  args="(name:string)",
		  returns = "(nil)"
		},		

		className={
		  type="function",
		  description="获取控件类型名",
		  args="(nil)",
		  returns = "(type:string)"
		},			
		pos={
		  type="function",
		  description="获取控件位置",
		  args="(nil)",
		  returns = "(pos:{x,y,w,h})"
		},
		setPos={
		  type="function",
		  description="设置控件位置",
		  args="(pos:{x,y,w,h})",
		  returns = "(nil)"
		},	
		width={
		  type="function",
		  description="获取控件宽度",
		  args="(nil)",
		  returns = "(width:number)"
		},	

		height={
		  type="function",
		  description="获取控件高度",
		  args="(nil)",
		  returns = "(height:number)"
		},	
		x={
		  type="function",
		  description="获取控件x坐标",
		  args="(nil)",
		  returns = "(x:number)"
		},	

		y={
		  type="function",
		  description="获取控件y坐标",
		  args="(nil)",
		  returns = "(y:number)"
		},	
		padding={
		  type="function",
		  description="获取控件padding",
		  args="(nil)",
		  returns = "(padding:{x,y,w,h})"
		},
		setPadding={
		  type="function",
		  description="设置控件padding",
		  args="(pos:{x,y,w,h})",
		  returns = "(nil)"
		},
		fixedXY={
		  type="function",
		  description="获取控件fixedXY",
		  args="(nil)",
		  returns = "(fixedXY:{x,y})"
		},
		setFixedXY={
		  type="function",
		  description="设置控件fixedXY",
		  args="(size:{x,y})",
		  returns = "(nil)"
		},
		
		fixedWidth={
		  type="function",
		  description="获取控件fixed宽度",
		  args="(nil)",
		  returns = "(fixedWidth:number)"
		},
		setFixedWidth={
		  type="function",
		  description="设置控件fixed宽度",
		  args="(fixedWidth:number)",
		  returns = "(nil)"
		},
		fixedHeight={
		  type="function",
		  description="获取控件fixed高度",
		  args="(nil)",
		  returns = "(fixedHeight:number)"
		},
		setFixedHeight={
		  type="function",
		  description="设置控件fixed高度",
		  args="(fixedHeight:number)",
		  returns = "(nil)"
		},	
		
		minWidth={
		  type="function",
		  description="获取控件最小宽度",
		  args="(nil)",
		  returns = "(minWidth:number)"
		},
		setMinWidth={
		  type="function",
		  description="设置控件最小宽度",
		  args="(minWidth:number)",
		  returns = "(nil)"
		},			
		maxWidth={
		  type="function",
		  description="获取控件最小宽度",
		  args="(nil)",
		  returns = "(maxWidth:number)"
		},
		setMaxWidth={
		  type="function",
		  description="设置控件最小宽度",
		  args="(maxWidth:number)",
		  returns = "(nil)"
		},			
		
		minHeight={
		  type="function",
		  description="获取控件最小高度",
		  args="(nil)",
		  returns = "(minHeight:number)"
		},
		setMinHeight={
		  type="function",
		  description="设置控件最小高度",
		  args="(minHeight:number)",
		  returns = "(nil)"
		},			
		maxHeight={
		  type="function",
		  description="获取控件最小高度",
		  args="(nil)",
		  returns = "(maxHeight:number)"
		},
		setMaxHeight={
		  type="function",
		  description="设置控件最小高度",
		  args="(maxHeight:number)",
		  returns = "(nil)"
		},			
		
		
		
		
		
		
	},
	description = "控件父类，基本控件属性。",
    type = "class" 
  },
  
  CLabelUI={
	childs={
		
	},
 	description = "控件父类，基本控件属性。",
    type = "class",
	inherits="CControlUI"
  },
 
 },

 description = "DuiLib表，包含所有Duilib导出接口。",
 type = "lib"
}



return {UI=UI}