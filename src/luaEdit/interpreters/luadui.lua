-- Copyright 2011-12 Paul Kulchenko, ZeroBrane LLC

local luadui
local win = ide.osname == "Windows"
local mac = ide.osname == "Macintosh"

return {
  name = "Luadui",
  description = "Luadui UI engine",
  api = {"baselib","luajit2","luadui"},
  frun = function(self,wfilename,rundebug)
    luadui = luadui or ide.config.path.luadui -- check if the path is configured
    if not luadui then
      local sep = win and ';' or ':'
      local default =
           win and (GenerateProgramFilesPath('luadui', sep)..sep)
        or mac and ('/Applications/luadui.app/Contents/MacOS'..sep)
        or ''
      local path = default
                 ..(os.getenv('PATH') or '')..sep
                 ..(GetPathWithSep(self:fworkdir(wfilename)))..sep
                 ..(os.getenv('HOME') and GetPathWithSep(os.getenv('HOME'))..'bin' or '')
      local paths = {}
      for p in path:gmatch("[^"..sep.."]+") do
        luadui = luadui or GetFullPathIfExists(p, win and 'luadui.exe' or 'luadui')
        table.insert(paths, p)
      end
      if not luadui then
        DisplayOutput("Can't find luadui executable in any of the following folders: "
          ..table.concat(paths, ", ").."\n")
        return
      end
    end

    if not GetFullPathIfExists(self:fworkdir(wfilename), 'main.lua') then
      DisplayOutput("Can't find 'main.lua' file in the current project folder.\n")
      return
    end

    if rundebug then
      DebuggerAttachDefault({runstart = ide.config.debugger.runonstart == true})
    end

    local params = ide.config.arg.any or ide.config.arg.luadui
    local cmd = ('"%s" "%s"%s%s'):format(luadui, self:fworkdir(wfilename),
      params and " "..params or "", rundebug and ' -debug' or '')
    -- CommandLineRun(cmd,wdir,tooutput,nohide,stringcallback,uid,endcallback)
    return CommandLineRun(cmd,self:fworkdir(wfilename),true,true)
  end,
  hasdebugger = true,
  fattachdebug = function(self) DebuggerAttachDefault() end,
  scratchextloop = true,
  takeparameters = true,
}
