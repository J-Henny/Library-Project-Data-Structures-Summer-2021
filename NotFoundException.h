
#ifndef PA_MAIN_NOTFOUNDEXCEPTION_H
#define PA_MAIN_NOTFOUNDEXCEPTION_H

class NotFoundException : public std::logic_error
{
public:
    NotFoundException(const std::string& message = "")
            : std::logic_error("Not Found Exception: " + message)  {   }

};

#endif //PA_MAIN_NOTFOUNDEXCEPTION_H
