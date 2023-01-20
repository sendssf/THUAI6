#include <optional>
#include <string>
#include "AI.h"
#include "API.h"
#include "utils.hpp"
#include "structures.h"
#define PI 3.14159265358979323846

HumanDebugAPI::HumanDebugAPI(ILogic& logic, bool file, bool print, bool warnOnly, int64_t playerID) :
    logic(logic)
{
    std::string fileName = "logs/api-" + std::to_string(playerID) + "-log.txt";
    auto fileLogger = std::make_shared<spdlog::sinks::basic_file_sink_mt>(fileName, true);
    auto printLogger = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
    std::string pattern = "[api " + std::to_string(playerID) + "] [%H:%M:%S.%e] [%l] %v";
    fileLogger->set_pattern(pattern);
    printLogger->set_pattern(pattern);
    if (file)
        fileLogger->set_level(spdlog::level::trace);
    else
        fileLogger->set_level(spdlog::level::off);
    if (print)
        printLogger->set_level(spdlog::level::info);
    else
        printLogger->set_level(spdlog::level::off);
    if (warnOnly)
        printLogger->set_level(spdlog::level::warn);
    logger = std::make_unique<spdlog::logger>("apiLogger", spdlog::sinks_init_list{fileLogger, printLogger});
}

ButcherDebugAPI::ButcherDebugAPI(ILogic& logic, bool file, bool print, bool warnOnly, int64_t playerID) :
    logic(logic)
{
    std::string fileName = "logs/api-" + std::to_string(playerID) + "-log.txt";
    auto fileLogger = std::make_shared<spdlog::sinks::basic_file_sink_mt>(fileName, true);
    auto printLogger = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
    std::string pattern = "[api" + std::to_string(playerID) + "] [%H:%M:%S.%e] [%l] %v";
    fileLogger->set_pattern(pattern);
    printLogger->set_pattern(pattern);
    if (file)
        fileLogger->set_level(spdlog::level::trace);
    else
        fileLogger->set_level(spdlog::level::off);
    if (print)
        printLogger->set_level(spdlog::level::info);
    else
        printLogger->set_level(spdlog::level::off);
    if (warnOnly)
        printLogger->set_level(spdlog::level::warn);
    logger = std::make_unique<spdlog::logger>("apiLogger", spdlog::sinks_init_list{fileLogger, printLogger});
}

void HumanDebugAPI::StartTimer()
{
    StartPoint = std::chrono::system_clock::now();
    std::time_t t = std::chrono::system_clock::to_time_t(StartPoint);
    logger->info("=== AI.play() ===");
    logger->info("StartTimer: {}", std::ctime(&t));
}

void ButcherDebugAPI::StartTimer()
{
    StartPoint = std::chrono::system_clock::now();
    std::time_t t = std::chrono::system_clock::to_time_t(StartPoint);
    logger->info("=== AI.play() ===");
    logger->info("StartTimer: {}", std::ctime(&t));
}

void HumanDebugAPI::EndTimer()
{
    logger->info("Time elapsed: {}ms", Time::TimeSinceStart(StartPoint));
}

void ButcherDebugAPI::EndTimer()
{
    logger->info("Time elapsed: {}ms", Time::TimeSinceStart(StartPoint));
}

int HumanDebugAPI::GetFrameCount() const
{
    return logic.GetCounter();
}

int ButcherDebugAPI::GetFrameCount() const
{
    return logic.GetCounter();
}

std::future<bool> HumanDebugAPI::Move(int64_t timeInMilliseconds, double angleInRadian)
{
    logger->info("Move: timeInMilliseconds = {}, angleInRadian = {}, at {}ms", timeInMilliseconds, angleInRadian, Time::TimeSinceStart(StartPoint));
    return std::async(std::launch::async, [&]()
                      { return logic.Move(timeInMilliseconds, angleInRadian); });
}

std::future<bool> HumanDebugAPI::MoveDown(int64_t timeInMilliseconds)
{
    return Move(timeInMilliseconds, 0);
}

std::future<bool> HumanDebugAPI::MoveRight(int64_t timeInMilliseconds)
{
    return Move(timeInMilliseconds, PI * 0.5);
}

std::future<bool> HumanDebugAPI::MoveUp(int64_t timeInMilliseconds)
{
    return Move(timeInMilliseconds, PI);
}

std::future<bool> HumanDebugAPI::MoveLeft(int64_t timeInMilliseconds)
{
    return Move(timeInMilliseconds, PI * 1.5);
}

std::future<bool> ButcherDebugAPI::Move(int64_t timeInMilliseconds, double angleInRadian)
{
    logger->info("Move: timeInMilliseconds = {}, angleInRadian = {}, at {}ms", timeInMilliseconds, angleInRadian, Time::TimeSinceStart(StartPoint));
    return std::async(std::launch::async, [&]()
                      { return logic.Move(timeInMilliseconds, angleInRadian); });
}

std::future<bool> ButcherDebugAPI::MoveDown(int64_t timeInMilliseconds)
{
    return Move(timeInMilliseconds, 0);
}

std::future<bool> ButcherDebugAPI::MoveRight(int64_t timeInMilliseconds)
{
    return Move(timeInMilliseconds, PI * 0.5);
}

std::future<bool> ButcherDebugAPI::MoveUp(int64_t timeInMilliseconds)
{
    return Move(timeInMilliseconds, PI);
}

std::future<bool> ButcherDebugAPI::MoveLeft(int64_t timeInMilliseconds)
{
    return Move(timeInMilliseconds, PI * 1.5);
}

std::future<bool> HumanDebugAPI::PickProp(THUAI6::PropType prop)
{
    logger->info("PickProp: prop = {}, at {}ms", THUAI6::propDict[prop], Time::TimeSinceStart(StartPoint));
    return std::async(std::launch::async, [&]()
                      { return logic.PickProp(prop); });
}

std::future<bool> HumanDebugAPI::UseProp()
{
    logger->info("UseProp: at {}ms", Time::TimeSinceStart(StartPoint));
    return std::async(std::launch::async, [&]()
                      { return logic.UseProp(); });
}

std::future<bool> ButcherDebugAPI::PickProp(THUAI6::PropType prop)
{
    logger->info("PickProp: prop = {}, at {}ms", THUAI6::propDict[prop], Time::TimeSinceStart(StartPoint));
    return std::async(std::launch::async, [&]()
                      { return logic.PickProp(prop); });
}

std::future<bool> ButcherDebugAPI::UseProp()
{
    logger->info("UseProp: at {}ms", Time::TimeSinceStart(StartPoint));
    return std::async(std::launch::async, [&]()
                      { return logic.UseProp(); });
}

std::future<bool> HumanDebugAPI::UseSkill()
{
    logger->info("UseSkill: at {}ms", Time::TimeSinceStart(StartPoint));
    return std::async(std::launch::async, [&]()
                      { return logic.UseSkill(); });
}

std::future<bool> ButcherDebugAPI::UseSkill()
{
    logger->info("UseSkill: at {}ms", Time::TimeSinceStart(StartPoint));
    return std::async(std::launch::async, [&]()
                      { return logic.UseSkill(); });
}

std::future<bool> HumanDebugAPI::SendMessage(int64_t toID, std::string message)
{
    logger->info("SendMessage: toID = {}, message = {}, at {}ms", toID, message, Time::TimeSinceStart(StartPoint));
    return std::async(std::launch::async, [&]()
                      { return logic.SendMessage(toID, message); });
}

std::future<bool> ButcherDebugAPI::SendMessage(int64_t toID, std::string message)
{
    logger->info("SendMessage: toID = {}, message = {}, at {}ms", toID, message, Time::TimeSinceStart(StartPoint));
    return std::async(std::launch::async, [&]()
                      { return logic.SendMessage(toID, message); });
}

std::future<bool> HumanDebugAPI::HaveMessage()
{
    logger->info("HaveMessage: at {}ms", Time::TimeSinceStart(StartPoint));
    return std::async(std::launch::async, [&]()
                      { return logic.HaveMessage(); });
}

std::future<bool> ButcherDebugAPI::HaveMessage()
{
    logger->info("HaveMessage: at {}ms", Time::TimeSinceStart(StartPoint));
    return std::async(std::launch::async, [&]()
                      { return logic.HaveMessage(); });
}

std::future<std::optional<std::pair<int64_t, std::string>>> HumanDebugAPI::GetMessage()
{
    logger->info("GetMessage: at {}ms", Time::TimeSinceStart(StartPoint));
    return std::async(std::launch::async, [&]()
                      { return logic.GetMessage(); });
}

std::future<std::optional<std::pair<int64_t, std::string>>> ButcherDebugAPI::GetMessage()
{
    logger->info("GetMessage: at {}ms", Time::TimeSinceStart(StartPoint));
    return std::async(std::launch::async, [&]()
                      { return logic.GetMessage(); });
}

std::future<bool> HumanDebugAPI::Wait()
{
    logger->info("Wait: at {}ms", Time::TimeSinceStart(StartPoint));
    if (logic.GetCounter() == -1)
        return std::async(std::launch::async, [&]()
                          { return false; });
    else
        return std::async(std::launch::async, [&]()
                          { return logic.WaitThread(); });
}

std::future<bool> ButcherDebugAPI::Wait()
{
    logger->info("Wait: at {}ms", Time::TimeSinceStart(StartPoint));
    if (logic.GetCounter() == -1)
        return std::async(std::launch::async, [&]()
                          { return false; });
    else
        return std::async(std::launch::async, [&]()
                          { return logic.WaitThread(); });
}

std::vector<std::shared_ptr<const THUAI6::Butcher>> HumanDebugAPI::GetButcher() const
{
    return logic.GetButchers();
}

std::vector<std::shared_ptr<const THUAI6::Human>> HumanDebugAPI::GetHuman() const
{
    return logic.GetHumans();
}

std::vector<std::shared_ptr<const THUAI6::Butcher>> ButcherDebugAPI::GetButcher() const
{
    return logic.GetButchers();
}

std::vector<std::shared_ptr<const THUAI6::Human>> ButcherDebugAPI::GetHuman() const
{
    return logic.GetHumans();
}

std::vector<std::shared_ptr<const THUAI6::Prop>> HumanDebugAPI::GetProps() const
{
    return logic.GetProps();
}

std::vector<std::shared_ptr<const THUAI6::Prop>> ButcherDebugAPI::GetProps() const
{
    return logic.GetProps();
}

std::vector<std::vector<THUAI6::PlaceType>> HumanDebugAPI::GetFullMap() const
{
    return logic.GetFullMap();
}

THUAI6::PlaceType HumanDebugAPI::GetPlaceType(int32_t CellX, int32_t CellY) const
{
    return logic.GetPlaceType(CellX, CellY);
}

THUAI6::PlaceType ButcherDebugAPI::GetPlaceType(int32_t CellX, int32_t CellY) const
{
    return logic.GetPlaceType(CellX, CellY);
}

std::vector<std::vector<THUAI6::PlaceType>> ButcherDebugAPI::GetFullMap() const
{
    return logic.GetFullMap();
}

const std::vector<int64_t> HumanDebugAPI::GetPlayerGUIDs() const
{
    return logic.GetPlayerGUIDs();
}

const std::vector<int64_t> ButcherDebugAPI::GetPlayerGUIDs() const
{
    return logic.GetPlayerGUIDs();
}

std::future<bool> HumanDebugAPI::StartFixMachine()
{
    logger->info("StartFixMachine: at {}ms", Time::TimeSinceStart(StartPoint));
    return std::async(std::launch::async, [&]()
                      { return logic.StartFixMachine(); });
}

std::future<bool> HumanDebugAPI::EndFixMachine()
{
    logger->info("EndFixMachine: at {}ms", Time::TimeSinceStart(StartPoint));
    return std::async(std::launch::async, [&]()
                      { return logic.EndFixMachine(); });
}

std::future<bool> HumanDebugAPI::StartSaveHuman()
{
    logger->info("StartSaveHuman: at {}ms", Time::TimeSinceStart(StartPoint));
    return std::async(std::launch::async, [&]()
                      { return logic.StartSaveHuman(); });
}

std::future<bool> HumanDebugAPI::EndSaveHuman()
{
    logger->info("EndSaveHuman: at {}ms", Time::TimeSinceStart(StartPoint));
    return std::async(std::launch::async, [&]()
                      { return logic.EndSaveHuman(); });
}

std::future<bool> HumanDebugAPI::Escape()
{
    logger->info("Escape: at {}ms", Time::TimeSinceStart(StartPoint));
    return std::async(std::launch::async, [&]()
                      { return logic.Escape(); });
}

std::shared_ptr<const THUAI6::Human> HumanDebugAPI::GetSelfInfo() const
{
    return logic.HumanGetSelfInfo();
}

std::future<bool> ButcherDebugAPI::Attack(double angleInRadian)
{
    logger->info("Attack: angleInRadian = {}, at {}ms", angleInRadian, Time::TimeSinceStart(StartPoint));
    return std::async(std::launch::async, [&]()
                      { return logic.Attack(angleInRadian); });
}

std::future<bool> ButcherDebugAPI::CarryHuman()
{
    logger->info("CarryHuman: at {}ms", Time::TimeSinceStart(StartPoint));
    return std::async(std::launch::async, [&]()
                      { return logic.CarryHuman(); });
}

std::future<bool> ButcherDebugAPI::ReleaseHuman()
{
    logger->info("ReleaseHuman: at {}ms", Time::TimeSinceStart(StartPoint));
    return std::async(std::launch::async, [&]()
                      { return logic.ReleaseHuman(); });
}

std::future<bool> ButcherDebugAPI::HangHuman()
{
    logger->info("HangHuman: at {}ms", Time::TimeSinceStart(StartPoint));
    return std::async(std::launch::async, [&]()
                      { return logic.HangHuman(); });
}

std::shared_ptr<const THUAI6::Butcher> ButcherDebugAPI::GetSelfInfo() const
{
    return logic.ButcherGetSelfInfo();
}

void HumanDebugAPI::Play(IAI& ai)
{
    ai.play(*this);
}

void ButcherDebugAPI::Play(IAI& ai)
{
    ai.play(*this);
}
