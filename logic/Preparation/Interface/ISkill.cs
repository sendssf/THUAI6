﻿using Preparation.Interface;
using Preparation.Utility;

namespace Preparation.Interface
{
    public interface ISkill
    {
    }
    public interface IPassiveSkill : ISkill
    {
    }
    public interface IActiveSkill : ISkill
    {
        public int SkillCD { get; }
        public int DurationTime { get; } //技能持续时间
        public object ActiveSkillLock { get; }
        public bool IsBeingUsed { get; set; }
    }
    public class CanBeginToCharge : IActiveSkill
    {
        public int SkillCD => GameData.commonSkillCD * 2;
        public int DurationTime => GameData.commonSkillTime * 3 / 10;

        private readonly object commonSkillLock = new object();
        public object ActiveSkillLock => commonSkillLock;

        public bool isBeingUsed = false;
        public bool IsBeingUsed
        {
            get => isBeingUsed; set => isBeingUsed = value;
        }
    }

    public class BecomeInvisible : IActiveSkill
    {
        public int SkillCD => GameData.commonSkillCD * 4 / 3;
        public int DurationTime => GameData.commonSkillTime;

        private readonly object commonSkillLock = new object();
        public object ActiveSkillLock => commonSkillLock;

        public bool isBeingUsed = false;
        public bool IsBeingUsed
        {
            get => isBeingUsed; set => isBeingUsed = value;
        }
    }

    public class Punish : IActiveSkill
    {
        public int SkillCD => GameData.commonSkillCD;
        public int DurationTime => 0;

        private readonly object commonSkillLock = new object();
        public object ActiveSkillLock => commonSkillLock;

        public bool isBeingUsed = false;
        public bool IsBeingUsed
        {
            get => isBeingUsed; set => isBeingUsed = value;
        }
    }

    public class Rouse : IActiveSkill
    {
        public int SkillCD => GameData.commonSkillCD * 4;
        public int DurationTime => 0;

        private readonly object commonSkillLock = new object();
        public object ActiveSkillLock => commonSkillLock;

        public bool isBeingUsed = false;
        public bool IsBeingUsed
        {
            get => isBeingUsed; set => isBeingUsed = value;
        }
    }

    public class Encourage : IActiveSkill
    {
        public int SkillCD => GameData.commonSkillCD * 4;
        public int DurationTime => 0;

        private readonly object commonSkillLock = new object();
        public object ActiveSkillLock => commonSkillLock;

        public bool isBeingUsed = false;
        public bool IsBeingUsed
        {
            get => isBeingUsed; set => isBeingUsed = value;
        }
    }

    public class Inspire : IActiveSkill
    {
        public int SkillCD => GameData.commonSkillCD * 4;
        public int DurationTime => 0;

        private readonly object commonSkillLock = new object();
        public object ActiveSkillLock => commonSkillLock;

        public bool isBeingUsed = false;
        public bool IsBeingUsed
        {
            get => isBeingUsed; set => isBeingUsed = value;
        }
    }

    public class Howl : IActiveSkill
    {
        public int SkillCD => GameData.commonSkillCD * 25 / 30;
        public int DurationTime => 0;

        private readonly object commonSkillLock = new object();
        public object ActiveSkillLock => commonSkillLock;

        public bool isBeingUsed = false;
        public bool IsBeingUsed
        {
            get => isBeingUsed; set => isBeingUsed = value;
        }
    }

    public class ShowTime : IActiveSkill
    {
        public int SkillCD => GameData.commonSkillCD * 8 / 3;
        public int DurationTime => GameData.commonSkillTime;

        private readonly object commonSkillLock = new();
        public object ActiveSkillLock => commonSkillLock;

        public bool isBeingUsed = false;
        public bool IsBeingUsed
        {
            get => isBeingUsed; set => isBeingUsed = value;
        }
    }

    public class JumpyBomb : IActiveSkill
    {
        public int SkillCD => GameData.commonSkillCD / 2;
        public int DurationTime => GameData.commonSkillTime * 3 / 10;
        private readonly object commonSkillLock = new object();
        public object ActiveSkillLock => commonSkillLock;

        public bool isBeingUsed = false;
        public bool IsBeingUsed
        {
            get => isBeingUsed; set => isBeingUsed = value;
        }
    }

    public class UseKnife : IActiveSkill
    {
        public int SkillCD => GameData.commonSkillCD;
        public int DurationTime => GameData.commonSkillTime / 10;
        private readonly object commonSkillLock = new object();
        public object ActiveSkillLock => commonSkillLock;

        public bool isBeingUsed = false;
        public bool IsBeingUsed
        {
            get => isBeingUsed; set => isBeingUsed = value;
        }
    }

    public class UseRobot : IActiveSkill
    {
        public int SkillCD => GameData.commonSkillCD / 300;
        public int DurationTime => 0;
        private readonly object commonSkillLock = new();
        public object ActiveSkillLock => commonSkillLock;

        public bool isBeingUsed = false;
        public bool IsBeingUsed
        {
            get => isBeingUsed; set => isBeingUsed = value;
        }
    }

    public class WriteAnswers : IActiveSkill
    {
        public int SkillCD => GameData.commonSkillCD;
        public int DurationTime => 0;
        private readonly object commonSkillLock = new object();
        public object ActiveSkillLock => commonSkillLock;

        private int degreeOfMeditation = 0;
        public int DegreeOfMeditation
        {
            get => degreeOfMeditation;
            set
            {
                lock (commonSkillLock)
                {
                    degreeOfMeditation = value;
                }
            }
        }
        public bool isBeingUsed = false;
        public bool IsBeingUsed
        {
            get => isBeingUsed; set => isBeingUsed = value;
        }
    }

    public class SummonGolem : IActiveSkill
    {
        public int SkillCD => GameData.commonSkillCD;
        public int DurationTime => 0;
        private readonly object commonSkillLock = new object();
        public object ActiveSkillLock => commonSkillLock;

        private IGolem? golemSummoned = null;
        public IGolem? GolemSummoned
        {
            get => golemSummoned;
            set
            {
                lock (commonSkillLock)
                {
                    golemSummoned = value;
                }
            }
        }

        public bool isBeingUsed = false;
        public bool IsBeingUsed
        {
            get => isBeingUsed; set => isBeingUsed = value;
        }
    }

    public class NullSkill : IActiveSkill
    {
        public int SkillCD => GameData.commonSkillCD;
        public int DurationTime => GameData.commonSkillTime;
        private readonly object commonSkillLock = new object();
        public object ActiveSkillLock => commonSkillLock;

        public bool isBeingUsed = false;
        public bool IsBeingUsed
        {
            get => isBeingUsed; set => isBeingUsed = false;
        }
    }

    public static class SkillFactory
    {
        public static IActiveSkill FindIActiveSkill(ActiveSkillType activeSkillType)
        {
            switch (activeSkillType)
            {
                case ActiveSkillType.BecomeInvisible:
                    return new BecomeInvisible();
                case ActiveSkillType.UseKnife:
                    return new UseKnife();
                case ActiveSkillType.Howl:
                    return new Howl();
                case ActiveSkillType.Encourage:
                    return new Encourage();
                case ActiveSkillType.CanBeginToCharge:
                    return new CanBeginToCharge();
                case ActiveSkillType.Punish:
                    return new Punish();
                case ActiveSkillType.JumpyBomb:
                    return new JumpyBomb();
                case ActiveSkillType.WriteAnswers:
                    return new WriteAnswers();
                case ActiveSkillType.SummonGolem:
                    return new SummonGolem();
                case ActiveSkillType.UseRobot:
                    return new UseRobot();
                case ActiveSkillType.Rouse:
                    return new Rouse();
                case ActiveSkillType.Inspire:
                    return new Inspire();
                case ActiveSkillType.ShowTime:
                    return new ShowTime();
                default:
                    return new NullSkill();
            }
        }

        public static ActiveSkillType FindActiveSkillType(IActiveSkill ActiveSkill)
        {
            switch (ActiveSkill)
            {
                case BecomeInvisible:
                    return ActiveSkillType.BecomeInvisible;
                case Howl:
                    return ActiveSkillType.Howl;
                case UseKnife:
                    return ActiveSkillType.UseKnife;
                case Encourage:
                    return ActiveSkillType.Encourage;
                case CanBeginToCharge:
                    return ActiveSkillType.CanBeginToCharge;
                case Inspire:
                    return ActiveSkillType.Inspire;
                case Punish:
                    return ActiveSkillType.Punish;
                case JumpyBomb:
                    return ActiveSkillType.JumpyBomb;
                case WriteAnswers:
                    return ActiveSkillType.WriteAnswers;
                case SummonGolem:
                    return ActiveSkillType.SummonGolem;
                case UseRobot:
                    return ActiveSkillType.UseRobot;
                case Rouse:
                    return ActiveSkillType.Rouse;
                case ShowTime:
                    return ActiveSkillType.ShowTime;
                default:
                    return ActiveSkillType.Null;
            }
        }
    }
}