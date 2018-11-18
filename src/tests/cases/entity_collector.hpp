CASE("EntityCollector add, get_by_name and size works correctly."){
	flow::EntityCollector entity_collector;
	entity_collector.add( std::make_shared<TestEntity>("test1") );
	entity_collector.add( std::make_shared<TestEntity>("test2") );

	try{
		EXPECT( (entity_collector.get_by_name("test1")->get_name() == "test1") );
		EXPECT( (entity_collector.get_by_name("test2")->get_name() == "test2") );
		EXPECT(entity_collector.size() == 2);
	} catch(flow::exception::EntityFindByName& e) {
		EXPECT(false);
	}
	
	EXPECT_THROWS( (entity_collector.get_by_name("test3")->get_name() == "test3") );
},
CASE("EntityCollector add, get_by_group and size works correctly."){
	flow::EntityCollector entity_collector;
	entity_collector.add( std::make_shared<TestEntity>("test1", "g1") );
	entity_collector.add( std::make_shared<TestEntity>("test2", "g2") );
	entity_collector.add( std::make_shared<TestEntity>("test3", "g1") );
	entity_collector.add( std::make_shared<TestEntity>("test4", "g2") );
	entity_collector.add( std::make_shared<TestEntity>("test5", "g1") );
	try{
		flow::EntityMap entities = entity_collector.get_by_group("g2");
		EXPECT(entities.size() == 2);
		for(flow::EntityPair& pair: entities) {
			EXPECT( ((pair.entity->get_name() == "test2") || (pair.entity->get_name() == "test4")) );
		}

		flow::EntityMap entities2 = entity_collector.get_by_group("g1");
		EXPECT(entities2.size() == 3);
		for(flow::EntityPair& pair: entities2) {
			EXPECT( ((pair.entity->get_name() == "test1") || (pair.entity->get_name() == "test3") || (pair.entity->get_name() == "test5")) );
		}
	} catch(flow::exception::EntityFindByGroup& e) {
		EXPECT(false);
	}
	EXPECT_THROWS( (entity_collector.get_by_group("g3").size() > 0) );
},