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
    /// Get the IQ file to playback on the specified target and output. Skydel tries to keep the sampling rate as low as possible. File may be upsampled if it doesn't match with the supported sampling rates.
    ///
    /// Name   Type   Description
    /// ------ ------ -------------------------
    /// Output int    Output index (zero based)
    /// Id     string Target identifier
    ///

    class GetModulationTargetIQPlayback;
    typedef std::shared_ptr<GetModulationTargetIQPlayback> GetModulationTargetIQPlaybackPtr;
    
    
    class GetModulationTargetIQPlayback : public CommandBase
    {
    public:
      inline static const char* const CmdName = "GetModulationTargetIQPlayback";
      inline static const char* const Documentation = "Get the IQ file to playback on the specified target and output. Skydel tries to keep the sampling rate as low as possible. File may be upsampled if it doesn't match with the supported sampling rates.\n"      "\n"      "Name   Type   Description\n"      "------ ------ -------------------------\n"      "Output int    Output index (zero based)\n"      "Id     string Target identifier";
      inline static const char* const TargetId = "";



          GetModulationTargetIQPlayback()
            : CommandBase(CmdName, TargetId)
          {}

          GetModulationTargetIQPlayback(int output, const std::string& id)
            : CommandBase(CmdName, TargetId)
          {

            setOutput(output);
            setId(id);
          }


          static GetModulationTargetIQPlaybackPtr create(int output, const std::string& id)
          {
            return std::make_shared<GetModulationTargetIQPlayback>(output, id);
          }

      static GetModulationTargetIQPlaybackPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetModulationTargetIQPlayback>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<int>::is_valid(m_values["Output"])
                  && parse_json<std::string>::is_valid(m_values["Id"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"Output", "Id"}; 
        return names; 
      }
      


          int executePermission() const
          {
            return EXECUTE_IF_IDLE;
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
    REGISTER_COMMAND_TO_FACTORY(GetModulationTargetIQPlayback);
  }
}

