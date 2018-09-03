#pragma once

namespace wee {

    struct shared_library {
        void* _handle;
        
        void open(const std::string& pt) {
            _handle = dlopen(pt.c_str(), RTLD_NOW);
            if(!_handle) {
                throw std::runtime_error(std::string(dlerror()));
            }
        }
        void close() {
            dlclose(_handle);
        }

        template <typename T>
        void sym(const std::string& fn, void** res) {
            *res = (void*)dlsym(_handle, fn.c_str());
        }
    };

#define PLUGIN_API_VERSION 1
        
#ifdef WIN32
# define WEE_PLUGIN_EXPORT __declspec(dllexport)
#else
# define WEE_PLUGIN_EXPORT // empty
#endif

    typedef plugin* (*fn_instance)(void);

    struct plugin {
        struct details {
            int api_version;
            const char* filename;
            const char* classname;
            const char* plugin_name;
            const char* plugin_version;
            fn_instance instance;
        };
    };

#define WEE_PLUGIN_DEFAULT  \
    PLUGIN_API_VERSION, \
    __FILE__

#define WEE_PLUGIN(classType, pluginName, pluginVersion)    \
    extern "C" {    \
        WEE_PLUGIN_EXPORT wee::plugin* _instance() {\
            static classType _;                     \
            return &_;                              \
        }                                           \
        WEE_PLUGIN_EXPORT wee::plugin::details exports = {  \
            WEE_PLUGIN_DEFAULT,                             \
            #classType,                                     \
            pluginName,                                     \
            pluginVersion,                                  \
            _instance                                       \
        };                                                  \
    }
}
