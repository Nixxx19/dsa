#include <vector>
#include <algorithm>
#include <climits>

using namespace std;
class Solution
{
public:
    int mostBooked(int n, vector<vector<int>>& meetings)
    {
        sort(meetings.begin(), meetings.end(),
             [](const vector<int>& a, const vector<int>& b)
             {
                 return a[0] < b[0];
             });

        vector<long long> roomFreeTime(n, 0);
        vector<int> roomMeetingCount(n, 0);

        for (const auto& meeting : meetings)
        {
            int start = meeting[0], end = meeting[1];
            long long duration = end - start;
            bool assigned = false;

            for (int room = 0; room < n; ++room)
            {
                if (roomFreeTime[room] <= start)
                {
                    roomFreeTime[room] = end;
                    roomMeetingCount[room]++;
                    assigned = true;
                    break;
                }
            }

            if (!assigned)
            {
                long long earliestTime = LLONG_MAX;
                int chosenRoom = -1;

                for (int room = 0; room < n; ++room)
                {
                    if (roomFreeTime[room] < earliestTime)
                    {
                        earliestTime = roomFreeTime[room];
                        chosenRoom = room;
                    }
                }

                roomFreeTime[chosenRoom] += duration;
                roomMeetingCount[chosenRoom]++;
            }
        }

        int maxMeetings = 0;
        int resultRoom = 0;

        for (int i = 0; i < n; ++i)
        {
            if (roomMeetingCount[i] > maxMeetings)
            {
                maxMeetings = roomMeetingCount[i];
                resultRoom = i;
            }
        }

        return resultRoom;
    }
};
