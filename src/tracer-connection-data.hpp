#pragma once

#include "daemon-connection-data.hpp"

namespace PS {

class TracerConnectionData : public DaemonConnectionData {
  public:
    explicit TracerConnectionData(Connection<std::unique_ptr<DaemonConnectionData>>* connection)
        : DaemonConnectionData(connection) {}

    bool handle_packet(const char* buffer, size_t length) override;

    void make_process_attached(pid_t pid, MakeConnectionData* make_data);

    bool has_child_with_pid(pid_t pid);

    pid_t get_ppid(pid_t pid) {
        auto it = m_tracer_event_handler.m_pid_database.find(pid);
        if (it == m_tracer_event_handler.m_pid_database.end())
            return 0;
        return it->second.ppid;
    }

  private:
    TracerEventHandler m_tracer_event_handler{};
};

} // namespace PS