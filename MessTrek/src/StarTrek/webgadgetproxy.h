#ifndef WEBGADGETPROXY_H
#define WEBGADGETPROXY_H

#include "../Untouchables/WebGadget.h"

class WebGadgetProxy{
public:
    WebGadgetProxy( Untouchables::WebGadget *wg ) : m_wg( wg ) {}

    virtual string parameter(string parameterName) {
        return m_wg->parameter(parameterName);
    }

    virtual void* variable(string variableName) {
        return m_wg->variable(variableName);
    }

    virtual void writeLine(string message) {
        m_wg->writeLine(message);
    }

private:
    Untouchables::WebGadget *m_wg;
};

#endif // WEBGADGETPROXY_H
