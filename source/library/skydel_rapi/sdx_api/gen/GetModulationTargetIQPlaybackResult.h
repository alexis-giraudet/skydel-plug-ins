#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include <string>
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetModulationTargetIQPlayback.
    ///
    /// Name   Type         Description
    /// ------ ------------ -------------------------------------------------------------------------------------------------------------------------------------------------------------------
    /// Output int          Output index (zero based)
    /// Files  array string The paths to the IQ Playback files. Note: only one file is currently supported, the additional files will be ignored.
    /// Gain   int          The gain associated to this output (dB). This value has to be between the radio's minimum and maximum value. A negative value means to use the radio default value.
    /// Id     string       Target identifier
    ///

    class GetModulationTargetIQPlaybackResult;
    typedef std::shared_ptr<GetModulationTargetIQPlaybackResult> GetModulationTargetIQPlaybackResultPtr;
    
    
    class GetModulationTargetIQPlaybackResult : public CommandResult
    {
    public:
      inline static const char* const CmdName = "GetModulationTargetIQPlaybackResult";
      inline static const char* const Documentation = "Result of GetModulationTargetIQPlayback.\n"      "\n"      "Name   Type         Description\n"      "------ ------------ -------------------------------------------------------------------------------------------------------------------------------------------------------------------\n"      "Output int          Output index (zero based)\n"      "Files  array string The paths to the IQ Playback files. Note: only one file is currently supported, the additional files will be ignored.\n"      "Gain   int          The gain associated to this output (dB). This value has to be between the radio's minimum and maximum value. A negative value means to use the radio default value.\n"      "Id     string       Target identifier";
      inline static const char* const TargetId = "";



          GetModulationTargetIQPlaybackResult()
            : CommandResult(CmdName, TargetId)
          {}

          GetModulationTargetIQPlaybackResult(int output, const std::vector<std::string>& files, int gain, const std::string& id)
            : CommandResult(CmdName, TargetId)
          {

            setOutput(output);
            setFiles(files);
            setGain(gain);
            setId(id);
          }

          GetModulationTargetIQPlaybackResult(CommandBasePtr relatedCommand, int output, const std::vector<std::string>& files, int gain, const std::string& id)
            : CommandResult(CmdName, TargetId, relatedCommand)
          {

            setOutput(output);
            setFiles(files);
            setGain(gain);
            setId(id);
          }



          static GetModulationTargetIQPlaybackResultPtr create(int output, const std::vector<std::string>& files, int gain, const std::string& id)
          {
            return std::make_shared<GetModulationTargetIQPlaybackResult>(output, files, gain, id);
          }

          static GetModulationTargetIQPlaybackResultPtr create(CommandBasePtr relatedCommand, int output, const std::vector<std::string>& files, int gain, const std::string& id)
          {
            return std::make_shared<GetModulationTargetIQPlaybackResult>(relatedCommand, output, files, gain, id);
          }

      static GetModulationTargetIQPlaybackResultPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetModulationTargetIQPlaybackResult>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<int>::is_valid(m_values["Output"])
                  && parse_json<std::vector<std::string>>::is_valid(m_values["Files"])
                  && parse_json<int>::is_valid(m_values["Gain"])
                  && parse_json<std::string>::is_valid(m_values["Id"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"Output", "Files", "Gain", "Id"}; 
        return names; 
      }
      


          int output() const
          {
            return parse_json<int>::parse(m_values["Output"]);
          }

          void setOutput(int output)
          {
            m_values.AddMember("Output", parse_json<int>::format(output, m_values.GetAllocator()), m_values.GetAllocator());
          }



          std::vector<std::string> files() const
          {
            return parse_json<std::vector<std::string>>::parse(m_values["Files"]);
          }

          void setFiles(const std::vector<std::string>& files)
          {
            m_values.AddMember("Files", parse_json<std::vector<std::string>>::format(files, m_values.GetAllocator()), m_values.GetAllocator());
          }



          int gain() const
          {
            return parse_json<int>::parse(m_values["Gain"]);
          }

          void setGain(int gain)
          {
            m_values.AddMember("Gain", parse_json<int>::format(gain, m_values.GetAllocator()), m_values.GetAllocator());
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
    REGISTER_COMMAND_TO_FACTORY(GetModulationTargetIQPlaybackResult);
  }
}

