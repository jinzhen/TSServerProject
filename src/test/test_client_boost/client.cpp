#include <iostream>
#include "boost/thread/thread.hpp"
#include "boost/progress.hpp"
#include "boost/asio.hpp"

using namespace std;
using namespace boost;
using namespace boost::asio;

#define PORT_TEST 5555
#define BLOCK_SIZE 64*1024

int main()
{
    io_service iosev; 
    ip::tcp::socket socket(iosev);
    ip::tcp::endpoint ep(ip::address_v4::from_string("127.0.0.1"), PORT_TEST);
    system::error_code ec; 
    socket.connect(ep,ec); 
    if (ec)
    {
        cout << system::system_error(ec).what() << endl;
        return -1; 
    }

    char buf[] = "mei tui";
    size_t len;
    for (;;)
    {
        len = 0;
        len = socket.write_some(buffer(buf), ec);
        cout << "write " << len << endl;
        sleep(5); 
    } 
    socket.close();
    return 0;
}
