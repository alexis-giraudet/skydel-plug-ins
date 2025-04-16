#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set the GPU associated with a RF output of a modulation target.
    ///
    /// Name   Type   Description
    /// ------ ------ --------------------------------------
    /// GpuIdx int    The gpu associated with the RF output.
    /// Output int    Output index (zero based)
    /// Id     string Target identifier
    ///

    class SetGpu;
    typedef std::shared_ptr<SetGpu> SetGpuPtr;
    
    
    class SetGpu : public CommandBase
    {
    public:
      inline static const char* const CmdName = "SetGpu";
      inline static const char* const Documentation = "Set the GPU associated with a RF output of a modulation target.\n"      "\n"      "Name   Type   Description\n"      "------ ------ --------------------------------------\n"      "GpuIdx int    The gpu associated with the RF output.\n"      "Output int    Output index (zero based)\n"      "Id     string Target identifier";
      inline static const char* const TargetId = "";



          SetGpu()
            : CommandBase(CmdName, TargetId)
          {}

          SetGpu(int gpuIdx, int output, const std::string& id)
            : CommandBase(CmdName, TargetId)
          {

            setGpuIdx(gpuIdx);
            setOutput(output);
            setId(id);
          }


          static SetGpuPtr create(int gpuIdx, int output, const std::string& id)
          {
            return std::make_shared<SetGpu>(gpuIdx, output, id);
          }

      static SetGpuPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<SetGpu>(ptr);
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
      


          int executePermission() const
          {
            return EXECUTE_IF_IDLE;
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
    REGISTER_COMMAND_TO_FACTORY(SetGpu);
  }
}

