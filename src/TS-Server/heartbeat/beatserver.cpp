/*
 * beatserver.cpp
 *
 *  Created on: Jan 23, 2013
 *      Author: hl
 */
#include "beatserverdef.hpp"
#include <iostream>
#include <boost/bind.hpp>

using namespace std;

CBeatServer::CBeatServer(io_service & io) : ios(io),
				acceptor(ios, ip::tcp::endpoint(ip::tcp::v4(), 5555))
{
	this->start();
}

void CBeatServer::start(void)
{
	sockt_pt sock(new ip::tcp::socket(ios));					/// < 创建socket对象
	acceptor.async_accept(*sock, bind(&CBeatServer::accept_handler, 	/// < 监听
			this, placeholders::error, sock));
}

void CBeatServer::accept_handler(const system::error_code & ec, sockt_pt sock)
{
//	this->start();												/// < 继续等待
	if (ec)														/// < 发生错误
		return;
	cout << "client: " << sock->remote_endpoint().address() << endl;
	shared_ptr<vector<char> > str(new vector<char>(100, 0));
	for (;;)
	{
		/// <  异步方式
//		cout << "HHHHHH # " << endl;
//		sock->async_read_some(buffer(*str),
//				bind(&CBeatServer::read_handler, this, placeholders::error, str));

		/// <  同步方式接收数据
		char buf[100] = {0};
		size_t len = sock->receive(buffer(buf));
		cout << buf << endl;
	}
//	this->start();												/// < 再次启动接受异步连接
}

void CBeatServer::read_handler(const system::error_code & ec, shared_ptr<vector<char> > str)
{
	if (ec)
		return;
	cout << "read data: " << &(*str)[0] << endl;
}
