
#include "gen/GetSVAntennaModelForSV.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSVAntennaModelForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSVAntennaModelForSV::CmdName = "GetSVAntennaModelForSV";
    const char* const GetSVAntennaModelForSV::Documentation = "Get the antenna model used by the SV.";

    REGISTER_COMMAND_FACTORY(GetSVAntennaModelForSV);


    GetSVAntennaModelForSV::GetSVAntennaModelForSV()
      : CommandBase(CmdName)
    {}

    GetSVAntennaModelForSV::GetSVAntennaModelForSV(const std::string& system, int svId)
      : CommandBase(CmdName)
    {

      setSystem(system);
      setSvId(svId);
    }

    GetSVAntennaModelForSVPtr GetSVAntennaModelForSV::create(const std::string& system, int svId)
    {
      return std::make_shared<GetSVAntennaModelForSV>(system, svId);
    }

    GetSVAntennaModelForSVPtr GetSVAntennaModelForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetSVAntennaModelForSV>(ptr);
    }

    bool GetSVAntennaModelForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["SvId"])
        ;

    }

    std::string GetSVAntennaModelForSV::documentation() const { return Documentation; }


    int GetSVAntennaModelForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetSVAntennaModelForSV::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void GetSVAntennaModelForSV::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetSVAntennaModelForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetSVAntennaModelForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
