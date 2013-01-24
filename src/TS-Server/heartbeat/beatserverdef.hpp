/*
 * beatserver.hpp
 *
 *  Created on: Jan 23, 2013
 *      Author: hl
 */

#ifndef BEATSERVERDEF_HPP_
#define BEATSERVERDEF_HPP_

#ifdef _MSC_VER
#define _WIN32_WINNT 0x0501	/// < 避免VC下编译警告
#endif
//#define BOOST_REGEX_NO_LIB
//#define BOOST_DATE_TIME_SOURCE
//#define BOOST_SYSTME_NO_LIB
#include <boost/asio.hpp>
#include <boost/shared_ptr.hpp>
#include <vector>

using namespace std;
using namespace boost;
using namespace boost::asio;

typedef shared_ptr<ip::tcp::socket> sockt_pt;	/// < 智能指针，异步调用后能够继续使用(存在于程序的整个生命周期)

class CBeatServer
{
public:
	CBeatServer(io_service & io);
public:
	void start();
	void accept_handler(const system::error_code & ec, sockt_pt sock);
	void read_handler(const system::error_code & ec, shared_ptr<vector<char> > str);
private:
	io_service & ios;			/// < io_service对象，完成程序和操作系统的交互
	ip::tcp::acceptor acceptor;	/// < 接收器对象
};

#endif /* BEATSERVERDEF_HPP_ */
