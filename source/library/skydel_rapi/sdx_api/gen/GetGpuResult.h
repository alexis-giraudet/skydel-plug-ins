#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetGpu.
    ///
    /// Name   Type   Description
    /// ------ ------ --------------------------------------
    /// GpuIdx int    The gpu associated with the RF output.
    /// Output int    Output index (zero based)
    /// Id     string Target identifier
    ///

    class GetGpuResult;
    typedef std::shared_ptr<GetGpuResult> GetGpuResultPtr;
    
    
    class GetGpuResult : public CommandResult
    {
    public:
      inline static const char* const CmdName = "GetGpuResult";
      inline static const char* const Documentation = "Result of GetGpu.\n"      "\n"      "Name   Type   Description\n"      "------ ------ --------------------------------------\n"      "GpuIdx int    The gpu associated with the RF output.\n"      "Output int    Output index (zero based)\n"      "Id     string Target identifier";
      inline static const char* const TargetId = "";



          GetGpuResult()
            : CommandResult(CmdName, TargetId)
          {}

          GetGpuResult(int gpuIdx, int output, const std::string& id)
            : CommandResult(CmdName, TargetId)
          {

            setGpuIdx(gpuIdx);
            setOutput(output);
            setId(id);
          }

          GetGpuResult(CommandBasePtr relatedCommand, int gpuIdx, int output, const std::string& id)
            : CommandResult(CmdName, TargetId, relatedCommand)
          {

            setGpuIdx(gpuIdx);
            setOutput(output);
            setId(id);
          }



          static GetGpuResultPtr create(int gpuIdx, int output, const std::string& id)
          {
            return std::make_shared<GetGpuResult>(gpuIdx, output, id);
          }

          static GetGpuResultPtr create(CommandBasePtr relatedCommand, int gpuIdx, int output, const std::string& id)
          {
            return std::make_shared<GetGpuResult>(relatedCommand, gpuIdx, output, id);
          }

      static GetGpuResultPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetGpuResult>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<int>::is_valid(m_values["GpuIdx"])
                  && parse_json<int>::is_valid(m_values["Output"])
                  && parse_json<std::string>::is_valid(m_values["Id"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"GpuIdx", "Output", "Id"}; 
        return names; 
      }
      


          int gpuIdx() const
          {
            return parse_json<int>::parse(m_values["GpuIdx"]);
          }

          void setGpuIdx(int gpuIdx)
          {
            m_values.AddMember("GpuIdx", parse_json<int>::format(gpuIdx, m_values.GetAllocator()), m_values.GetAllocator());
          }



          int output() const
          {
            return parse_json<int>::parse(m_values["Output"]);
          }

          void setOutput(int output)
          {
            m_values.AddMember("Output", parse_json<int>::format(output, m_values.GetAllocator()), m_values.GetAllocator());
          }



          std::string id() const
          {
            return parse_json<std::string>::parse(m_values["Id"]);
          }

          void setId(const std::string& id)
          {
            m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(GetGpuResult);
  }
}

