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
    /// Export the performance graph data into a csv file.
    ///
    /// Name        Type   Description
    /// ----------- ------ -----------------------------------------------------------------------------------------------
    /// Path        string The full path to the csv file.
    /// Overwriting bool   Overwrite an existing file if set to true, return an error if set to false and the file exists.
    ///

    class ExportPerformanceDataToCSV;
    typedef std::shared_ptr<ExportPerformanceDataToCSV> ExportPerformanceDataToCSVPtr;
    
    
    class ExportPerformanceDataToCSV : public CommandBase
    {
    public:
      inline static const char* const CmdName = "ExportPerformanceDataToCSV";
      inline static const char* const Documentation = "Export the performance graph data into a csv file.\n"      "\n"      "Name        Type   Description\n"      "----------- ------ -----------------------------------------------------------------------------------------------\n"      "Path        string The full path to the csv file.\n"      "Overwriting bool   Overwrite an existing file if set to true, return an error if set to false and the file exists.";
      inline static const char* const TargetId = "";



          ExportPerformanceDataToCSV()
            : CommandBase(CmdName, TargetId)
          {}

          ExportPerformanceDataToCSV(const std::string& path, bool overwriting)
            : CommandBase(CmdName, TargetId)
          {

            setPath(path);
            setOverwriting(overwriting);
          }


          static ExportPerformanceDataToCSVPtr create(const std::string& path, bool overwriting)
          {
            return std::make_shared<ExportPerformanceDataToCSV>(path, overwriting);
          }

      static ExportPerformanceDataToCSVPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<ExportPerformanceDataToCSV>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<std::string>::is_valid(m_values["Path"])
                  && parse_json<bool>::is_valid(m_values["Overwriting"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"Path", "Overwriting"}; 
        return names; 
      }
      


          int executePermission() const
          {
            return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
          }


          std::string path() const
          {
            return parse_json<std::string>::parse(m_values["Path"]);
          }

          void setPath(const std::string& path)
          {
            m_values.AddMember("Path", parse_json<std::string>::format(path, m_values.GetAllocator()), m_values.GetAllocator());
          }



          bool overwriting() const
          {
            return parse_json<bool>::parse(m_values["Overwriting"]);
          }

          void setOverwriting(bool overwriting)
          {
            m_values.AddMember("Overwriting", parse_json<bool>::format(overwriting, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(ExportPerformanceDataToCSV);
  }
}

