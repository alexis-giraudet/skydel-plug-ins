#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"
#include <optional>
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Export ionospheric grid GIVEI.
    ///
    /// Name            Type            Description
    /// --------------- --------------- -------------------------------
    /// Overwriting     bool            Overwrite the old file if true.
    /// Path            string          Grid file path
    /// ServiceProvider optional string The service provider (optional)
    ///

    class ExportIonoGridGIVEI;
    typedef std::shared_ptr<ExportIonoGridGIVEI> ExportIonoGridGIVEIPtr;
    
    
    class ExportIonoGridGIVEI : public CommandBase
    {
    public:
      inline static const char* const CmdName = "ExportIonoGridGIVEI";
      inline static const char* const Documentation = "Export ionospheric grid GIVEI.\n"      "\n"      "Name            Type            Description\n"      "--------------- --------------- -------------------------------\n"      "Overwriting     bool            Overwrite the old file if true.\n"      "Path            string          Grid file path\n"      "ServiceProvider optional string The service provider (optional)";
      inline static const char* const TargetId = "";



          ExportIonoGridGIVEI()
            : CommandBase(CmdName, TargetId)
          {}

          ExportIonoGridGIVEI(bool overwriting, const std::string& path, const std::optional<std::string>& serviceProvider = {})
            : CommandBase(CmdName, TargetId)
          {

            setOverwriting(overwriting);
            setPath(path);
            setServiceProvider(serviceProvider);
          }


          static ExportIonoGridGIVEIPtr create(bool overwriting, const std::string& path, const std::optional<std::string>& serviceProvider = {})
          {
            return std::make_shared<ExportIonoGridGIVEI>(overwriting, path, serviceProvider);
          }

      static ExportIonoGridGIVEIPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<ExportIonoGridGIVEI>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<bool>::is_valid(m_values["Overwriting"])
                  && parse_json<std::string>::is_valid(m_values["Path"])
                  && parse_json<std::optional<std::string>>::is_valid(m_values["ServiceProvider"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"Overwriting", "Path", "ServiceProvider"}; 
        return names; 
      }
      


          int executePermission() const
          {
            return EXECUTE_IF_IDLE;
          }


          bool overwriting() const
          {
            return parse_json<bool>::parse(m_values["Overwriting"]);
          }

          void setOverwriting(bool overwriting)
          {
            m_values.AddMember("Overwriting", parse_json<bool>::format(overwriting, m_values.GetAllocator()), m_values.GetAllocator());
          }



          std::string path() const
          {
            return parse_json<std::string>::parse(m_values["Path"]);
          }

          void setPath(const std::string& path)
          {
            m_values.AddMember("Path", parse_json<std::string>::format(path, m_values.GetAllocator()), m_values.GetAllocator());
          }



          std::optional<std::string> serviceProvider() const
          {
            return parse_json<std::optional<std::string>>::parse(m_values["ServiceProvider"]);
          }

          void setServiceProvider(const std::optional<std::string>& serviceProvider)
          {
            m_values.AddMember("ServiceProvider", parse_json<std::optional<std::string>>::format(serviceProvider, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(ExportIonoGridGIVEI);
  }
}

