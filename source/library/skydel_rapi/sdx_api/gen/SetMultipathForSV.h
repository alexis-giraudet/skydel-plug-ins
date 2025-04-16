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
    /// Add or update signal echo (multipath). Offsets (power loss, pseudorange, Doppler and carrier phase) are all relative to line-of-sight signal.
    /// If Id is not set, or unknown to Skydel, a new echo will be added. Otherwise, existing echo will be updated.
    ///
    /// Name         Type   Description
    /// ------------ ------ -------------------------------------------------------------------------------------------------------------
    /// Signal       string Accepted signal keys: "L1CA", "L1C", "L1P", "L1ME", "L1MR", "L2C", "L2P", "L2ME", "L2MR", "L5",
    ///                                           "G1", "G2", "E1", "E5a", "E5b", "B1", "B2", "B1C", "B2a", "B3I", "SBASL1",
    ///                                           "QZSSL1CA", "QZSSL1CB", "QZSSL1C", "QZSSL2C", "QZSSL5", "QZSSL1S", "QZSSL5S", "QZSSL6",
    ///                                           "NAVICL1", "NAVICL5", "NAVICS", "PULSARXL", "PULSARX1" and "PULSARX5"
    /// SvId         int    The satellite's SV ID
    /// PowerLoss    double Power loss in dB (value must be positive)
    /// Pseudorange  double Pseudorange offset in meters (value must be positive)
    /// Doppler      double Doppler frequency offset in Hz
    /// CarrierPhase double Carrier phase offset in radians
    /// Echo         int    Echo number [1..5], or use zero to let Skydel assign an echo number.
    /// Id           string Unique identifier.
    ///

    class SetMultipathForSV;
    typedef std::shared_ptr<SetMultipathForSV> SetMultipathForSVPtr;
    
    
    class SetMultipathForSV : public CommandBase
    {
    public:
      inline static const char* const CmdName = "SetMultipathForSV";
      inline static const char* const Documentation = "Add or update signal echo (multipath). Offsets (power loss, pseudorange, Doppler and carrier phase) are all relative to line-of-sight signal.\n"      "If Id is not set, or unknown to Skydel, a new echo will be added. Otherwise, existing echo will be updated.\n"      "\n"      "Name         Type   Description\n"      "------------ ------ -------------------------------------------------------------------------------------------------------------\n"      "Signal       string Accepted signal keys: \"L1CA\", \"L1C\", \"L1P\", \"L1ME\", \"L1MR\", \"L2C\", \"L2P\", \"L2ME\", \"L2MR\", \"L5\",\n"      "                                          \"G1\", \"G2\", \"E1\", \"E5a\", \"E5b\", \"B1\", \"B2\", \"B1C\", \"B2a\", \"B3I\", \"SBASL1\",\n"      "                                          \"QZSSL1CA\", \"QZSSL1CB\", \"QZSSL1C\", \"QZSSL2C\", \"QZSSL5\", \"QZSSL1S\", \"QZSSL5S\", \"QZSSL6\",\n"      "                                          \"NAVICL1\", \"NAVICL5\", \"NAVICS\", \"PULSARXL\", \"PULSARX1\" and \"PULSARX5\"\n"      "SvId         int    The satellite's SV ID\n"      "PowerLoss    double Power loss in dB (value must be positive)\n"      "Pseudorange  double Pseudorange offset in meters (value must be positive)\n"      "Doppler      double Doppler frequency offset in Hz\n"      "CarrierPhase double Carrier phase offset in radians\n"      "Echo         int    Echo number [1..5], or use zero to let Skydel assign an echo number.\n"      "Id           string Unique identifier.";
      inline static const char* const TargetId = "";



          SetMultipathForSV()
            : CommandBase(CmdName, TargetId)
          {}

          SetMultipathForSV(const std::string& signal, int svId, double powerLoss, double pseudorange, double doppler, double carrierPhase, int echo, const std::string& id)
            : CommandBase(CmdName, TargetId)
          {

            setSignal(signal);
            setSvId(svId);
            setPowerLoss(powerLoss);
            setPseudorange(pseudorange);
            setDoppler(doppler);
            setCarrierPhase(carrierPhase);
            setEcho(echo);
            setId(id);
          }


          static SetMultipathForSVPtr create(const std::string& signal, int svId, double powerLoss, double pseudorange, double doppler, double carrierPhase, int echo, const std::string& id)
          {
            return std::make_shared<SetMultipathForSV>(signal, svId, powerLoss, pseudorange, doppler, carrierPhase, echo, id);
          }

      static SetMultipathForSVPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<SetMultipathForSV>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<std::string>::is_valid(m_values["Signal"])
                  && parse_json<int>::is_valid(m_values["SvId"])
                  && parse_json<double>::is_valid(m_values["PowerLoss"])
                  && parse_json<double>::is_valid(m_values["Pseudorange"])
                  && parse_json<double>::is_valid(m_values["Doppler"])
                  && parse_json<double>::is_valid(m_values["CarrierPhase"])
                  && parse_json<int>::is_valid(m_values["Echo"])
                  && parse_json<std::string>::is_valid(m_values["Id"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"Signal", "SvId", "PowerLoss", "Pseudorange", "Doppler", "CarrierPhase", "Echo", "Id"}; 
        return names; 
      }
      


          int executePermission() const
          {
            return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
          }


          std::string signal() const
          {
            return parse_json<std::string>::parse(m_values["Signal"]);
          }

          void setSignal(const std::string& signal)
          {
            m_values.AddMember("Signal", parse_json<std::string>::format(signal, m_values.GetAllocator()), m_values.GetAllocator());
          }



          int svId() const
          {
            return parse_json<int>::parse(m_values["SvId"]);
          }

          void setSvId(int svId)
          {
            m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
          }



          double powerLoss() const
          {
            return parse_json<double>::parse(m_values["PowerLoss"]);
          }

          void setPowerLoss(double powerLoss)
          {
            m_values.AddMember("PowerLoss", parse_json<double>::format(powerLoss, m_values.GetAllocator()), m_values.GetAllocator());
          }



          double pseudorange() const
          {
            return parse_json<double>::parse(m_values["Pseudorange"]);
          }

          void setPseudorange(double pseudorange)
          {
            m_values.AddMember("Pseudorange", parse_json<double>::format(pseudorange, m_values.GetAllocator()), m_values.GetAllocator());
          }



          double doppler() const
          {
            return parse_json<double>::parse(m_values["Doppler"]);
          }

          void setDoppler(double doppler)
          {
            m_values.AddMember("Doppler", parse_json<double>::format(doppler, m_values.GetAllocator()), m_values.GetAllocator());
          }



          double carrierPhase() const
          {
            return parse_json<double>::parse(m_values["CarrierPhase"]);
          }

          void setCarrierPhase(double carrierPhase)
          {
            m_values.AddMember("CarrierPhase", parse_json<double>::format(carrierPhase, m_values.GetAllocator()), m_values.GetAllocator());
          }



          int echo() const
          {
            return parse_json<int>::parse(m_values["Echo"]);
          }

          void setEcho(int echo)
          {
            m_values.AddMember("Echo", parse_json<int>::format(echo, m_values.GetAllocator()), m_values.GetAllocator());
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
    REGISTER_COMMAND_TO_FACTORY(SetMultipathForSV);
  }
}

