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
    /// Import a sequence file.
    /// A sequence file is a CSV with one message type per line.
    ///
    /// Name     Type   Description
    /// -------- ------ ------------------------------------------------
    /// Signal   string Signal Name ("L2C" for example)
    /// Filename string Path to the CSV file on the simulator's machine.
    ///

    class MessageSequenceImport;
    typedef std::shared_ptr<MessageSequenceImport> MessageSequenceImportPtr;
    
    
    class MessageSequenceImport : public CommandBase
    {
    public:
      inline static const char* const CmdName = "MessageSequenceImport";
      inline static const char* const Documentation = "Import a sequence file.\n"      "A sequence file is a CSV with one message type per line.\n"      "\n"      "Name     Type   Description\n"      "-------- ------ ------------------------------------------------\n"      "Signal   string Signal Name (\"L2C\" for example)\n"      "Filename string Path to the CSV file on the simulator's machine.";
      inline static const char* const TargetId = "";



          MessageSequenceImport()
            : CommandBase(CmdName, TargetId)
          {}

          MessageSequenceImport(const std::string& signal, const std::string& filename)
            : CommandBase(CmdName, TargetId)
          {

            setSignal(signal);
            setFilename(filename);
          }


          static MessageSequenceImportPtr create(const std::string& signal, const std::string& filename)
          {
            return std::make_shared<MessageSequenceImport>(signal, filename);
          }

      static MessageSequenceImportPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<MessageSequenceImport>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<std::string>::is_valid(m_values["Signal"])
                  && parse_json<std::string>::is_valid(m_values["Filename"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"Signal", "Filename"}; 
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



          std::string filename() const
          {
            return parse_json<std::string>::parse(m_values["Filename"]);
          }

          void setFilename(const std::string& filename)
          {
            m_values.AddMember("Filename", parse_json<std::string>::format(filename, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(MessageSequenceImport);
  }
}

