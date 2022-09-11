#include <Application.hpp>

int main(int argc, char ** argv)
{
#ifdef _WIN32

    // Setup Windows socket library
    WSAData wsaData{};
    int result = WSAStartup(MAKEWORD(2,2), &wsaData);
    if (result != 0)
    {
        std::cout << "WSAStartup has failed!\n";
        return -1;
    }

    // Create a new application
    Application* application = new Application();
    application->Run();

    // Cleanup
    WSACleanup();
    delete application;

#elif !_WIN32

    Application* application = new Application();
    application->Run();
    delete application;

#endif
}