#include "request.h"

const std::string Request::COMMAND = "__command";
const std::string Request::STATUS = "__status";
const std::string Request::MESSAGE = "__message";
const std::string Request::STATUS_SUCCESS = "S";
const std::string Request::STATUS_FAILURE = "F";

Request::Request() {}

Request::Request(std::string s) {
    m_values = jsonDecode(s);
}

Request::Request(std::map<std::string, std::string> m) :
    m_values(m)
{}

std::string& Request::operator[](std::string s){
    return m_values[s];
}

Request::operator std::string () {
    return jsonEncode(m_values);
}

std::string Request::toString() {
    return jsonEncode(m_values);
}

bool Request::empty() {
    return m_values.empty();
}

bool Request::isSet(const std::string &s) {
    return (m_values.find(s) != m_values.end());
}

Command Request::getCommand(){
    std::string s = m_values[Request::COMMAND];
    Command res = atoi(s.c_str());
    return res;
}

std::string Request::getStatus() {
    return m_values[Request::STATUS];
}

std::string Request::get(std::string s) {
    return m_values[s];
}

std::string Request::getMessage() {
    return m_values[Request::MESSAGE];
}

std::map<std::string, std::string> Request::getMap(std::string s) {
    return jsonDecode(m_values[s]);
}

void Request::setCommand(Command i) {
    std::ostringstream s;
    s<<i;
    m_values[Request::COMMAND] = s.str();
}

void Request::setStatus(const std::string s) {
    m_values[Request::STATUS] = s;
}

void Request::setMessage(std::string s) {
    m_values[Request::MESSAGE] = s;
}

void Request::set(std::string key, std::string value) {
    m_values[key] = value;
}

void Request::setMap(std::string key, std::map<std::string,std::string> m) {
    m_values[key] = jsonEncode(m);
}

Request::~Request() {}
