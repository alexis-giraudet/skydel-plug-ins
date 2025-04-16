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
    /// Set the satellite pseudorange noise Gauss-Markov process attributes.
    ///
    /// Name    Type   Description
    /// ------- ------ --------------------------------------------------------------------------
    /// System  string "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS", "NavIC" or "PULSAR"
    /// SvId    int    Satellite SV ID.
    /// Process int    Gauss-Markov Process number (0 or 1)
    /// Enabled bool   If true, Gauss-Markov process is enabled
    /// Sigma   double Standard devition in meters [0..5000]
    /// Time    double Time constant [1..2000]
    /// Seed    int    Random seed
    ///

    class SetPseudorangeNoiseGaussMarkovForSV;
    typedef std::shared_ptr<SetPseudorangeNoiseGaussMarkovForSV> SetPseudorangeNoiseGaussMarkovForSVPtr;
    
    
    class SetPseudorangeNoiseGaussMarkovForSV : public CommandBase
    {
    public:
      inline static const char* const CmdName = "SetPseudorangeNoiseGaussMarkovForSV";
      inline static const char* const Documentation = "Set the satellite pseudorange noise Gauss-Markov process attributes.\n"      "\n"      "Name    Type   Description\n"      "------- ------ --------------------------------------------------------------------------\n"      "System  string \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"      "SvId    int    Satellite SV ID.\n"      "Process int    Gauss-Markov Process number (0 or 1)\n"      "Enabled bool   If true, Gauss-Markov process is enabled\n"      "Sigma   double Standard devition in meters [0..5000]\n"      "Time    double Time constant [1..2000]\n"      "Seed    int    Random seed";
      inline static const char* const TargetId = "";



          SetPseudorangeNoiseGaussMarkovForSV()
            : CommandBase(CmdName, TargetId)
          {}

          SetPseudorangeNoiseGaussMarkovForSV(const std::string& system, int svId, int process, bool enabled, double sigma, double time, int seed)
            : CommandBase(CmdName, TargetId)
          {

            setSystem(system);
            setSvId(svId);
            setProcess(process);
            setEnabled(enabled);
            setSigma(sigma);
            setTime(time);
            setSeed(seed);
          }


          static SetPseudorangeNoiseGaussMarkovForSVPtr create(const std::string& system, int svId, int process, bool enabled, double sigma, double time, int seed)
          {
            return std::make_shared<SetPseudorangeNoiseGaussMarkovForSV>(system, svId, process, enabled, sigma, time, seed);
          }

      static SetPseudorangeNoiseGaussMarkovForSVPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<SetPseudorangeNoiseGaussMarkovForSV>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<std::string>::is_valid(m_values["System"])
                  && parse_json<int>::is_valid(m_values["SvId"])
                  && parse_json<int>::is_valid(m_values["Process"])
                  && parse_json<bool>::is_valid(m_values["Enabled"])
                  && parse_json<double>::is_valid(m_values["Sigma"])
                  && parse_json<double>::is_valid(m_values["Time"])
                  && parse_json<int>::is_valid(m_values["Seed"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"System", "SvId", "Process", "Enabled", "Sigma", "Time", "Seed"}; 
        return names; 
      }
      


          int executePermission() const
          {
            return EXECUTE_IF_IDLE;
          }


          std::string system() const
          {
            return parse_json<std::string>::parse(m_values["System"]);
          }

          void setSystem(const std::string& system)
          {
            m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
          }



          int svId() const
          {
            return parse_json<int>::parse(m_values["SvId"]);
          }

          void setSvId(int svId)
          {
            m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
          }



          int process() const
          {
            return parse_json<int>::parse(m_values["Process"]);
          }

          void setProcess(int process)
          {
            m_values.AddMember("Process", parse_json<int>::format(process, m_values.GetAllocator()), m_values.GetAllocator());
          }



          bool enabled() const
          {
            return parse_json<bool>::parse(m_values["Enabled"]);
          }

          void setEnabled(bool enabled)
          {
            m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
          }



          double sigma() const
          {
            return parse_json<double>::parse(m_values["Sigma"]);
          }

          void setSigma(double sigma)
          {
            m_values.AddMember("Sigma", parse_json<double>::format(sigma, m_values.GetAllocator()), m_values.GetAllocator());
          }



          double time() const
          {
            return parse_json<double>::parse(m_values["Time"]);
          }

          void setTime(double time)
          {
            m_values.AddMember("Time", parse_json<double>::format(time, m_values.GetAllocator()), m_values.GetAllocator());
          }



          int seed() const
          {
            return parse_json<int>::parse(m_values["Seed"]);
          }

          void setSeed(int seed)
          {
            m_values.AddMember("Seed", parse_json<int>::format(seed, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(SetPseudorangeNoiseGaussMarkovForSV);
  }
}

