#define BOOST_LOG_DYN_LINK 1

#include <boost/log/trivial.hpp>
#include <boost/move/utility.hpp>
#include <boost/log/sources/logger.hpp>
#include <boost/log/sources/record_ostream.hpp>
#include <boost/log/sources/global_logger_storage.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>

#include <iostream>

namespace logging = boost::log;
namespace src = boost::log::sources;
namespace keywords = boost::log::keywords;



void logging_function1()
{
    src::logger lg;
//[ example_tutorial_logging_manual_logging
    logging::record rec = lg.open_record();
    if (rec)
    {
        logging::record_ostream strm(rec);
        strm << "Hello, World!";
        strm.flush();
        lg.push_record(boost::move(rec));
    }
//]
}

int test1(){
    BOOST_LOG_TRIVIAL(trace) << "A trace severity message";
    return 0;
}


#define g_debug()   BOOST_LOG_TRIVIAL(debug)
#define g_warn()   BOOST_LOG_TRIVIAL(warning)

int main (int argc, char* argv[]){
	g_debug() << "hello " << "debug " << 2;
    g_warn() << "hello " << "warn " << 3;
    
	return 0;
}
