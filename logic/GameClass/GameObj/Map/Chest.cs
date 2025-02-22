﻿using Preparation.Utility;

namespace GameClass.GameObj
{
    /// <summary>
    /// 箱子
    /// </summary>
    public class Chest : Immovable
    {
        public Chest(XY initPos) :
            base(initPos, GameData.numOfPosGridPerCell / 2, GameObjType.Chest)
        {
        }
        public override bool IsRigid => true;
        public override ShapeType Shape => ShapeType.Square;

        private readonly Prop[] propInChest = new Prop[GameData.maxNumOfPropInChest] { new NullProp(), new NullProp() };
        public Prop[] PropInChest => propInChest;

        private int openStartTime = 0;
        public int OpenStartTime => openStartTime;
        private Character? whoOpen = null;
        public Character? WhoOpen => whoOpen;
        public void Open(int startTime, Character character)
        {
            lock (GameObjReaderWriterLock)
            {
                openStartTime = startTime;
                whoOpen = character;
            }
        }
        public void StopOpen()
        {
            lock (GameObjReaderWriterLock)
            {
                openStartTime = 0;
                whoOpen = null;
            }
        }
    }
}
