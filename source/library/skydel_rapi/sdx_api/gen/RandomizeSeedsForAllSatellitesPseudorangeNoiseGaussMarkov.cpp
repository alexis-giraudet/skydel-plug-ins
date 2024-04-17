
#include "RandomizeSeedsForAllSatellitesPseudorangeNoiseGaussMarkov.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of RandomizeSeedsForAllSatellitesPseudorangeNoiseGaussMarkov
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const RandomizeSeedsForAllSatellitesPseudorangeNoiseGaussMarkov::CmdName = "RandomizeSeedsForAllSatellitesPseudorangeNoiseGaussMarkov";
    const char* const RandomizeSeedsForAllSatellitesPseudorangeNoiseGaussMarkov::Documentation = "Please note the command RandomizeSeedsForAllSatellitesPseudorangeNoiseGaussMarkov is deprecated since 21.3. You may use RandomizePseudorangeNoiseGaussMarkovSeedsForAllSV.\n"
      "\n"
      "Generate new seeds for pseudorange noise Gauss-Markov process error on all satellites.\n"
      "\n"
      "Name   Type   Description\n"
      "------ ------ --------------------------------------------------------------------------\n"
      "System string \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\"";
    const char* const RandomizeSeedsForAllSatellitesPseudorangeNoiseGaussMarkov::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(RandomizeSeedsForAllSatellitesPseudorangeNoiseGaussMarkov);
    REGISTER_COMMAND_TO_FACTORY_IMPL(RandomizeSeedsForAllSatellitesPseudorangeNoiseGaussMarkov);


    RandomizeSeedsForAllSatellitesPseudorangeNoiseGaussMarkov::RandomizeSeedsForAllSatellitesPseudorangeNoiseGaussMarkov()
      : CommandBase(CmdName, TargetId)
    {}

    RandomizeSeedsForAllSatellitesPseudorangeNoiseGaussMarkov::RandomizeSeedsForAllSatellitesPseudorangeNoiseGaussMarkov(const std::string& system)
      : CommandBase(CmdName, TargetId)
    {

      setSystem(system);
    }

    RandomizeSeedsForAllSatellitesPseudorangeNoiseGaussMarkovPtr RandomizeSeedsForAllSatellitesPseudorangeNoiseGaussMarkov::create(const std::string& system)
    {
      return std::make_shared<RandomizeSeedsForAllSatellitesPseudorangeNoiseGaussMarkov>(system);
    }

    RandomizeSeedsForAllSatellitesPseudorangeNoiseGaussMarkovPtr RandomizeSeedsForAllSatellitesPseudorangeNoiseGaussMarkov::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<RandomizeSeedsForAllSatellitesPseudorangeNoiseGaussMarkov>(ptr);
    }

    bool RandomizeSeedsForAllSatellitesPseudorangeNoiseGaussMarkov::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
        ;

    }

    std::string RandomizeSeedsForAllSatellitesPseudorangeNoiseGaussMarkov::documentation() const { return Documentation; }

    const std::vector<std::string>& RandomizeSeedsForAllSatellitesPseudorangeNoiseGaussMarkov::fieldNames() const 
    { 
      static const std::vector<std::string> names {"System"}; 
      return names; 
    }


    int RandomizeSeedsForAllSatellitesPseudorangeNoiseGaussMarkov::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string RandomizeSeedsForAllSatellitesPseudorangeNoiseGaussMarkov::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void RandomizeSeedsForAllSatellitesPseudorangeNoiseGaussMarkov::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
