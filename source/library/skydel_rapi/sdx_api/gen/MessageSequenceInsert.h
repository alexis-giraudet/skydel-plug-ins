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
    /// Insert message to sequence.
    ///
    /// Name   Type   Description
    /// ------ ------ -----------------------------------------------------------------------------------------------------------
    /// Signal string Signal Name ("L2C" for example)
    /// Index  int    Message index in sequence where to insert. Set to -1 to append the message type at the end of the sequence.
    /// Type   int    Message type to insert
    ///

    class MessageSequenceInsert;
    typedef std::shared_ptr<MessageSequenceInsert> MessageSequenceInsertPtr;
    
    
    class MessageSequenceInsert : public CommandBase
    {
    public:
      inline static const char* const CmdName = "MessageSequenceInsert";
      inline static const char* const Documentation = "Insert message to sequence.\n"      "\n"      "Name   Type   Description\n"      "------ ------ -----------------------------------------------------------------------------------------------------------\n"      "Signal string Signal Name (\"L2C\" for example)\n"      "Index  int    Message index in sequence where to insert. Set to -1 to append the message type at the end of the sequence.\n"      "Type   int    Message type to insert";
      inline static const char* const TargetId = "";



          MessageSequenceInsert()
            : CommandBase(CmdName, TargetId)
          {}

          MessageSequenceInsert(const std::string& signal, int index, int type)
            : CommandBase(CmdName, TargetId)
          {

            setSignal(signal);
            setIndex(index);
            setType(type);
          }


          static MessageSequenceInsertPtr create(const std::string& signal, int index, int type)
          {
            return std::make_shared<MessageSequenceInsert>(signal, index, type);
          }

      static MessageSequenceInsertPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<MessageSequenceInsert>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<std::string>::is_valid(m_values["Signal"])
                  && parse_json<int>::is_valid(m_values["Index"])
                  && parse_json<int>::is_valid(m_values["Type"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"Signal", "Index", "Type"}; 
        return names; 
      }
      


          int executePermission() const
          {
            return EXECUTE_IF_IDLE;
          }


          std::string signal() const
          {
            return parse_json<std::string>::parse(m_values["Signal"]);
          }

          void setSignal(const std::string& signal)
          {
            m_values.AddMember("Signal", parse_json<std::string>::format(signal, m_values.GetAllocator()), m_values.GetAllocator());
          }



          int index() const
          {
            return parse_json<int>::parse(m_values["Index"]);
          }

          void setIndex(int index)
          {
            m_values.AddMember("Index", parse_json<int>::format(index, m_values.GetAllocator()), m_values.GetAllocator());
          }



          int type() const
          {
            return parse_json<int>::parse(m_values["Type"]);
          }

          void setType(int type)
          {
            m_values.AddMember("Type", parse_json<int>::format(type, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(MessageSequenceInsert);
  }
}

