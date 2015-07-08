local uv=uv
assert(uv)

--dns解析
local url="www.baidu.com"
println("DNS 解析"..url)
assert(uv.getaddrinfo(url, nil, {
  socktype = "stream",
  family = "inet",
}, function (err, res)
  var_dump(res)
end))



--tcpserver
local server = uv.new_tcp()
assert(uv.tcp_bind(server, "127.0.0.1", 1234))
assert(uv.listen(server, 1,function ()
  local client = uv.new_tcp()
  assert(uv.accept(server, client))
  assert(uv.read_start(client, function (err, data)
	print("server read\n")
	var_dump(data)
	if data then
	  assert(uv.write(client, data))
	else
	  assert(uv.read_stop(client))
	  uv.close(client)
	  uv.close(server)
	end
  end, 2))
end))




--tcpclient
local socket = assert(uv.new_tcp())
assert(uv.tcp_connect(socket, "127.0.0.1", 1234, function ()
  assert(uv.read_start(socket, function (err, data)
	print("client read\n")
	var_dump(data)
	assert(not err, err)
	assert(uv.read_stop(socket))
	uv.close(socket)
  end))
  
  local req = assert(uv.write(socket, "Hello", function (err)
	assert(not err, err)
  end))
end))









