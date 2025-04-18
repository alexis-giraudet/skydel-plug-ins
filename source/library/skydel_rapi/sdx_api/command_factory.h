#ifndef COMMAND_FACTORY_H
#define COMMAND_FACTORY_H

#include <rapidjson/stringbuffer.h>
#include <rapidjson/writer.h>

#include <string>

#include "command_base.h"
#include "parse_json.hpp"

#define REGISTER_COMMAND_TO_FACTORY(COMMAND_CLASS_NAME)                               \
  inline CommandBasePtr functionToCreateCommand##COMMAND_CLASS_NAME()                 \
  {                                                                                   \
    return std::make_shared<COMMAND_CLASS_NAME>();                                    \
  }                                                                                   \
  inline static const auto isRegistered##COMMAND_CLASS_NAME =                         \
    CommandFactory::instance()->registerFactoryFunction(COMMAND_CLASS_NAME::TargetId, \
                                                        COMMAND_CLASS_NAME::CmdName,  \
                                                        functionToCreateCommand##COMMAND_CLASS_NAME);

namespace Sdx
{

class CommandFactory
{
public:
  static CommandFactory* instance();
  ~CommandFactory();
  CommandBasePtr createCommand(const std::string& serializedCommand, std::string* errorMsg = nullptr);
  CommandResultPtr createCommandResult(const std::string& serializedCommand, std::string* errorMsg = nullptr);
  using FactoryFunction = CommandBasePtr (*)();
  bool registerFactoryFunction(const std::string& targetID, const std::string& cmdName, FactoryFunction fct);

private:
  CommandFactory();
  struct Pimpl;
  std::unique_ptr<Pimpl> m;
};

} // namespace Sdx

// CommandBasePtr specialization
template<>
struct parse_json<Sdx::CommandBasePtr>
{
  static bool is_valid(const rapidjson::Value& value) { return value.IsObject(); }

  static Sdx::CommandBasePtr parse(const rapidjson::Value& value)
  {
    if (!is_valid(value))
      throw std::runtime_error("Unexpected value");
    std::string error;
    rapidjson::StringBuffer buffer;
    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
    value.Accept(writer);
    Sdx::CommandBasePtr ret = Sdx::CommandFactory::instance()->createCommand(buffer.GetString(), &error);
    if (!error.empty())
      throw std::runtime_error("Unexpected value: " + error);
    return ret;
  }

  static rapidjson::Document format(const Sdx::CommandBasePtr& ptr, rapidjson::Value::AllocatorType& alloc)
  {
    rapidjson::Document doc;
    doc.CopyFrom(ptr->values(), alloc);
    return doc;
  }
};

#endif // COMMAND_FACTORY_H
