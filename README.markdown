DoodleDrop 2DX Version
=======================

I use the state machine and message dispatch to this game.but there is some problem in it.
---------------------------------

1:I use BaseGameEntity as the Base Class for all the entities in the
project. and I want to use the Composite more than the Inheritance, so
at first,i want to let BaseGameEntity inherited from CCNode, and
composite with CCSprite.Because i want to let CCSprite only responsible
for render the texture.but when i want to decrease the draw call for the
game,then i import the CCSpriteBatchNode to batch all the entities.but
the CCSpriteBatchNode can only accept CCSprite as child.That's really
awful.

2:this question is more like a discussion about dispatching design.
SpiderCache is like the manager class for all the spiders, is it
propriate for it to receive the messages? or just let the single spider
receive the message?
