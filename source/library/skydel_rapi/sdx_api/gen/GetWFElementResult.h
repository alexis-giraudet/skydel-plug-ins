#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include <optional>
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetWFElement.
    ///
    /// Name                            Type            Description
    /// ------------------------------- --------------- -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    /// Element                         int             One-based index of the element. Value -1 adds a new element at the end of the list.
    /// Enabled                         bool            If True, this antenna element will be simulated.
    /// AntennaModelName                string          Antenna Model name for this element. Antenna models can be defined in Vehicle Antenna Model menu.
    /// LnaGain                         optional int    LNA gain to add to the element. If unspecified, default value is 0 dB. Value must be a positive integer between 0 dB and +25 dB.
    /// IsGaussianNoiseEnabled          optional bool   If true, add Gaussian noise to the GNSS outputs of the element to ensure realistic signal to noise ratio. If unspecified, default value is True. The Gaussian Noise seed used is unique for each output of each element of the Wavefront system.
    /// GaussianNoisePowerDensityOffset optional double The Noise Power Density Offset (dB/Hz) added to the base Gaussian Noise power density (-174 dB/Hz) on the GNSS outputs of the element. If Gaussian Noise is not enabled on the element, this offset has no effect. If unspecified, default value is 0 dB/Hz. Value must be between -10 and +10 dB/Hz.
    ///

    class GetWFElementResult;
    typedef std::shared_ptr<GetWFElementResult> GetWFElementResultPtr;
    
    
    class GetWFElementResult : public CommandResult
    {
    public:
      inline static const char* const CmdName = "GetWFElementResult";
      inline static const char* const Documentation = "Result of GetWFElement.\n"      "\n"      "Name                            Type            Description\n"      "------------------------------- --------------- -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n"      "Element                         int             One-based index of the element. Value -1 adds a new element at the end of the list.\n"      "Enabled                         bool            If True, this antenna element will be simulated.\n"      "AntennaModelName                string          Antenna Model name for this element. Antenna models can be defined in Vehicle Antenna Model menu.\n"      "LnaGain                         optional int    LNA gain to add to the element. If unspecified, default value is 0 dB. Value must be a positive integer between 0 dB and +25 dB.\n"      "IsGaussianNoiseEnabled          optional bool   If true, add Gaussian noise to the GNSS outputs of the element to ensure realistic signal to noise ratio. If unspecified, default value is True. The Gaussian Noise seed used is unique for each output of each element of the Wavefront system.\n"      "GaussianNoisePowerDensityOffset optional double The Noise Power Density Offset (dB/Hz) added to the base Gaussian Noise power density (-174 dB/Hz) on the GNSS outputs of the element. If Gaussian Noise is not enabled on the element, this offset has no effect. If unspecified, default value is 0 dB/Hz. Value must be between -10 and +10 dB/Hz.";
      inline static const char* const TargetId = "";



          GetWFElementResult()
            : CommandResult(CmdName, TargetId)
          {}

          GetWFElementResult(int element, bool enabled, const std::string& antennaModelName, const std::optional<int>& lnaGain = {}, const std::optional<bool>& isGaussianNoiseEnabled = {}, const std::optional<double>& gaussianNoisePowerDensityOffset = {})
            : CommandResult(CmdName, TargetId)
          {

            setElement(element);
            setEnabled(enabled);
            setAntennaModelName(antennaModelName);
            setLnaGain(lnaGain);
            setIsGaussianNoiseEnabled(isGaussianNoiseEnabled);
            setGaussianNoisePowerDensityOffset(gaussianNoisePowerDensityOffset);
          }

          GetWFElementResult(CommandBasePtr relatedCommand, int element, bool enabled, const std::string& antennaModelName, const std::optional<int>& lnaGain = {}, const std::optional<bool>& isGaussianNoiseEnabled = {}, const std::optional<double>& gaussianNoisePowerDensityOffset = {})
            : CommandResult(CmdName, TargetId, relatedCommand)
          {

            setElement(element);
            setEnabled(enabled);
            setAntennaModelName(antennaModelName);
            setLnaGain(lnaGain);
            setIsGaussianNoiseEnabled(isGaussianNoiseEnabled);
            setGaussianNoisePowerDensityOffset(gaussianNoisePowerDensityOffset);
          }



          static GetWFElementResultPtr create(int element, bool enabled, const std::string& antennaModelName, const std::optional<int>& lnaGain = {}, const std::optional<bool>& isGaussianNoiseEnabled = {}, const std::optional<double>& gaussianNoisePowerDensityOffset = {})
          {
            return std::make_shared<GetWFElementResult>(element, enabled, antennaModelName, lnaGain, isGaussianNoiseEnabled, gaussianNoisePowerDensityOffset);
          }

          static GetWFElementResultPtr create(CommandBasePtr relatedCommand, int element, bool enabled, const std::string& antennaModelName, const std::optional<int>& lnaGain = {}, const std::optional<bool>& isGaussianNoiseEnabled = {}, const std::optional<double>& gaussianNoisePowerDensityOffset = {})
          {
            return std::make_shared<GetWFElementResult>(relatedCommand, element, enabled, antennaModelName, lnaGain, isGaussianNoiseEnabled, gaussianNoisePowerDensityOffset);
          }

      static GetWFElementResultPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetWFElementResult>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<int>::is_valid(m_values["Element"])
                  && parse_json<bool>::is_valid(m_values["Enabled"])
                  && parse_json<std::string>::is_valid(m_values["AntennaModelName"])
                  && parse_json<std::optional<int>>::is_valid(m_values["LnaGain"])
                  && parse_json<std::optional<bool>>::is_valid(m_values["IsGaussianNoiseEnabled"])
                  && parse_json<std::optional<double>>::is_valid(m_values["GaussianNoisePowerDensityOffset"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"Element", "Enabled", "AntennaModelName", "LnaGain", "IsGaussianNoiseEnabled", "GaussianNoisePowerDensityOffset"}; 
        return names; 
      }
      


          int element() const
          {
            return parse_json<int>::parse(m_values["Element"]);
          }

          void setElement(int element)
          {
            m_values.AddMember("Element", parse_json<int>::format(element, m_values.GetAllocator()), m_values.GetAllocator());
          }



          bool enabled() const
          {
            return parse_json<bool>::parse(m_values["Enabled"]);
          }

          void setEnabled(bool enabled)
          {
            m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
          }



          std::string antennaModelName() const
          {
            return parse_json<std::string>::parse(m_values["AntennaModelName"]);
          }

          void setAntennaModelName(const std::string& antennaModelName)
          {
            m_values.AddMember("AntennaModelName", parse_json<std::string>::format(antennaModelName, m_values.GetAllocator()), m_values.GetAllocator());
          }



          std::optional<int> lnaGain() const
          {
            return parse_json<std::optional<int>>::parse(m_values["LnaGain"]);
          }

          void setLnaGain(const std::optional<int>& lnaGain)
          {
            m_values.AddMember("LnaGain", parse_json<std::optional<int>>::format(lnaGain, m_values.GetAllocator()), m_values.GetAllocator());
          }



          std::optional<bool> isGaussianNoiseEnabled() const
          {
            return parse_json<std::optional<bool>>::parse(m_values["IsGaussianNoiseEnabled"]);
          }

          void setIsGaussianNoiseEnabled(const std::optional<bool>& isGaussianNoiseEnabled)
          {
            m_values.AddMember("IsGaussianNoiseEnabled", parse_json<std::optional<bool>>::format(isGaussianNoiseEnabled, m_values.GetAllocator()), m_values.GetAllocator());
          }



          std::optional<double> gaussianNoisePowerDensityOffset() const
          {
            return parse_json<std::optional<double>>::parse(m_values["GaussianNoisePowerDensityOffset"]);
          }

          void setGaussianNoisePowerDensityOffset(const std::optional<double>& gaussianNoisePowerDensityOffset)
          {
            m_values.AddMember("GaussianNoisePowerDensityOffset", parse_json<std::optional<double>>::format(gaussianNoisePowerDensityOffset, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(GetWFElementResult);
  }
}

