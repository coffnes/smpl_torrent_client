#include <iostream>
#include <cxxopts/cxxopts.hpp>

int main(int argc, const char* argv[])
{
    cxxopts::Options options("SmplTorrentClient", "A simple, multi-threaded BitTorrent client written in C++");

    options.set_width(80).set_tab_expansion().add_options()
            ("t,torrent-file", "Path to the Torrent file", cxxopts::value<std::string>())
            ("o,output-dir", "The output directory to which the file will be downloaded", cxxopts::value<std::string>())
            ("n,thread-num", "Number of downloading threads to use", cxxopts::value<int>()->default_value("5"))
            ("l,logging", "Enable logging", cxxopts::value<bool>()->default_value("false"))
            ("f,log-file", "Path to the log file", cxxopts::value<std::string>()->default_value("../logs/client.log"))
            ("h,help", "Print arguments and their descriptions");

    try
    {
        auto parsedOptions = options.parse(argc, argv);
        if(parsedOptions.count("help"))
        {
            std::cout << options.help() << std::endl;
            return 0;
        }
    }
    catch(std::exception& e)
    {
        std::cout << "Error while parsing options: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}