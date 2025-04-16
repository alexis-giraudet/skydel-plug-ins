#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get all QZSS L1S augmentation's IDs.
    ///
    /// 
    ///

    class GetQzssL1SAugmentations;
    typedef std::shared_ptr<GetQzssL1SAugmentations> GetQzssL1SAugmentationsPtr;
    
    
    class GetQzssL1SAugmentations : public CommandBase
    {
    public:
      inline static const char* const CmdName = "GetQzssL1SAugmentations";
      inline static const char* const Documentation = "Get all QZSS L1S augmentation's IDs.";
      inline static const char* const TargetId = "";



          GetQzssL1SAugmentations()
            : CommandBase(CmdName, TargetId)
          {

          }


          static GetQzssL1SAugmentationsPtr create()
          {
            return std::make_shared<GetQzssL1SAugmentations>();
          }

      static GetQzssL1SAugmentationsPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetQzssL1SAugmentations>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {}; 
        return names; 
      }
      


          int executePermission() const
          {
            return EXECUTE_IF_IDLE;
          }
    };
    REGISTER_COMMAND_TO_FACTORY(GetQzssL1SAugmentations);
  }
}

