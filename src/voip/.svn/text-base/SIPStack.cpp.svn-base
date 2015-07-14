#include "SIPStack.h"

using namespace micro::voip;
using namespace micro::logging;

SIPTransport *SIPStack::transport = 0;
SIPStackListener *SIPStack::listener = 0;

bool SIPStack::create()
{
    // creating PJSUA
    return pjsua_create() == PJ_SUCCESS;
}

bool SIPStack::init(const SIPConfig &configuration)
{
    Logger logger("SIPStack");

    // initializing PJSUA
    pjsua_config config;
    pjsua_config_default(&config);

    QByteArray byteArray;
    byteArray = configuration.getUserAgent().toLatin1();
    config.user_agent = pj_str(byteArray.data());

    if (!configuration.getSTUNServer().isEmpty()) {
        byteArray = configuration.getSTUNServer().toLatin1();
        config.stun_host = pj_str(byteArray.data());
    }
    if (!configuration.getProxyServer().isEmpty()) {
        QString proxy("sip:");
        proxy.append(configuration.getProxyServer());
        if (!configuration.getProxyPort().isEmpty()) {
            proxy.append(":" + configuration.getProxyPort());
        }

        logger.debug(proxy);
        config.outbound_proxy_cnt = 1;
        byteArray = proxy.toLatin1();
        config.outbound_proxy[0] = pj_str(byteArray.data());
    }

    config.cb.on_incoming_call = &SIPStack::onIncomingCall;
    config.cb.on_call_state = &SIPStack::onCallState;
    config.cb.on_call_media_state = &SIPStack::onCallMediaState;
    config.cb.on_stream_created = &SIPStack::onStreamCreated;
    config.cb.on_reg_state = &SIPStack::onRegistrationState;
    // TODO: config.cb.*** - another callbacks

    pjsua_logging_config logConfig;
    pjsua_logging_config_default(&logConfig);
    byteArray = configuration.getLogFile().toLatin1();
    logConfig.log_filename = pj_str(byteArray.data());
    logConfig.console_level = 0;
    logConfig.level = 4;

    pjsua_media_config mediaConfig;
    pjsua_media_config_default(&mediaConfig);

    pj_status_t status = pjsua_init(&config, &logConfig, &mediaConfig);
    if (status != PJ_SUCCESS) {
        return false;
    }

    // start PJSUA
    status = pjsua_start();
    if (status != PJ_SUCCESS) {
        return false;
    }

    return true;
}

void SIPStack::destroy()
{
    // closing and destroying transport
    if (transport != 0) {
        transport->close(false);
        delete transport;
        transport = 0;
    }

    // destroying PJSUA
    pjsua_destroy();
}

void SIPStack::detectNATType()
{
    pj_status_t status = pjsua_detect_nat_type();
}

bool SIPStack::verifyURL(const QString &url)
{
    return (pjsua_verify_sip_url(url.toAscii().data()) == PJ_SUCCESS);
}

void SIPStack::onRegistrationState(pjsua_acc_id accountId)
{
    pjsua_acc_info accountInfo;
    pjsua_acc_get_info(accountId, &accountInfo);

    if (listener) {
        SIPAccount sipAccount(accountId);
        listener->onRegistrationState(sipAccount, accountInfo.status, accountInfo.online_status);
    }
}

void SIPStack::onIncomingCall(pjsua_acc_id accountId, pjsua_call_id callId, pjsip_rx_data *rxData)
{
    pjsua_call_info ci;

    PJ_UNUSED_ARG(accountId);
    PJ_UNUSED_ARG(rxData);

    if (listener) {
        SIPCall sipCall(callId);
        listener->onIncomingCall(sipCall);
    }
}

void SIPStack::onCallState(pjsua_call_id callId, pjsip_event *e)
{
    PJ_UNUSED_ARG(e);
    pjsua_call_info ci;
    pjsua_call_get_info(callId, &ci);

    QString str(pj_strbuf(&ci.state_text));

    if (listener) {
        SIPCall sipCall(callId);
        listener->onCallState(sipCall, (int) ci.state);
    }

    PJ_LOG(3,("onCallState", "Call %d state=%.*s", callId, (int)ci.state_text.slen, ci.state_text.ptr));
}

void SIPStack::onCallMediaState(pjsua_call_id callId)
{
    Logger logger("SIPStack");
    logger.debug("onCallMediaState");
    PJ_LOG(3,("onCallMediaState", "start"));
    pjsua_call_info ci;

    pjsua_call_get_info(callId, &ci);

    //pjsua_recorder_id id;
    //pj_str_t str = pj_str("./output.wav");
    //pjsua_recorder_create(&str, 0, NULL, 0, 0, &id);

    if (ci.media_status == PJSUA_CALL_MEDIA_ACTIVE) {
        // When media is active, connect call to sound device.
        pjsua_conf_connect(ci.conf_slot, 0);
        pjsua_conf_connect(0, ci.conf_slot);
    }
}

void SIPStack::onStreamCreated(pjsua_call_id callId, pjmedia_session *session, unsigned streamIdx, pjmedia_port **pPort)
{
    PJ_UNUSED_ARG(callId);
    PJ_UNUSED_ARG(session);
    PJ_UNUSED_ARG(streamIdx);
}
