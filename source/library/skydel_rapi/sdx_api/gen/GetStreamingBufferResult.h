#pragma once

#include <memory>

#include "command_factory.h"
#include "command_result.h"

namespace Sdx
{
namespace Cmd
{
///
/// Result of GetStreamingBuffer.
///
/// Name Type Description
/// ---- ---- -----------------------------
/// Size int  Streaming buffer size in msec
///

class GetStreamingBufferResult;
typedef std::shared_ptr<GetStreamingBufferResult> GetStreamingBufferResultPtr;

class GetStreamingBufferResult : public CommandResult
{
public:
  inline static const char* const CmdName = "GetStreamingBufferResult";
  inline static const char* const Documentation = "Result of GetStreamingBuffer.\n"
                                                  "\n"
                                                  "Name Type Description\n"
                                                  "---- ---- -----------------------------\n"
                                                  "Size int  Streaming buffer size in msec";
  inline static const char* const TargetId = "";

  GetStreamingBufferResult() : CommandResult(CmdName, TargetId) {}

  GetStreamingBufferResult(int size) : CommandResult(CmdName, TargetId) { setSize(size); }

  GetStreamingBufferResult(CommandBasePtr relatedCommand, int size) : CommandResult(CmdName, TargetId, relatedCommand)
  {

    setSize(size);
  }

  static GetStreamingBufferResultPtr create(int size) { return std::make_shared<GetStreamingBufferResult>(size); }

  static GetStreamingBufferResultPtr create(CommandBasePtr relatedCommand, int size)
  {
    return std::make_shared<GetStreamingBufferResult>(relatedCommand, size);
  }

  static GetStreamingBufferResultPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetStreamingBufferResult>(ptr);
  }

  virtual bool isValid() const override { return m_values.IsObject() && parse_json<int>::is_valid(m_values["Size"]); }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"Size"};
    return names;
  }

  int size() const { return parse_json<int>::parse(m_values["Size"]); }

  void setSize(int size)
  {
    m_values.AddMember("Size", parse_json<int>::format(size, m_values.GetAllocator()), m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(GetStreamingBufferResult);
} // namespace Cmd
} // namespace Sdx
