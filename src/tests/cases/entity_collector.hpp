CASE("EntityCollector add, get_by_name and size works correctly."){
	flow::EntityCollector entity_collector;
	//creating some sample tests entities.
	entity_collector.add( std::make_shared<TestEntity>("test1") );
	entity_collector.add( std::make_shared<TestEntity>("test2") );

	try{
		//expecting some simple questions to be answered as true. test1 should exist and have its name and test2 should do the same.
		EXPECT( (entity_collector.get_by_name("test1")->get_name() == "test1") );
		EXPECT( (entity_collector.get_by_name("test2")->get_name() == "test2") );
		EXPECT(entity_collector.size() == 2); // entire entity list should also be 2 items in size.
	} catch(flow::exception::EntityFindByName& e) {
		EXPECT(false); // if the questions are answered false then the test fails. If the get_by_name method doesn't find any entity then it should throw an exception.
	}
	
	EXPECT_THROWS( (entity_collector.get_by_name("test3")->get_name() == "test3") ); // expect it to throw because test3 doesn't exist.
},
CASE("EntityCollector add, get_by_group and size works correctly."){
	flow::EntityCollector entity_collector;
	//creating some sample tests entities. First parameter is entity name and second is group name.
	entity_collector.add( std::make_shared<TestEntity>("test1", "g1") );
	entity_collector.add( std::make_shared<TestEntity>("test2", "g2") );
	entity_collector.add( std::make_shared<TestEntity>("test3", "g1") );
	entity_collector.add( std::make_shared<TestEntity>("test4", "g2") );
	entity_collector.add( std::make_shared<TestEntity>("test5", "g1") );
	try{
		//expecting some simple questions to be answered as true.
		flow::EntityMap entities = entity_collector.get_by_group("g2");
		EXPECT(entities.size() == 2);
		int how_much_found = 0;
		for(flow::EntityPair& pair: entities) {
			if(pair.entity->get_name() == "test2") how_much_found++;
			if(pair.entity->get_name() == "test4") how_much_found++;
		}
		EXPECT( (how_much_found == entities.size()) );

		flow::EntityMap entities2 = entity_collector.get_by_group("g1");
		EXPECT(entities2.size() == 3);
		how_much_found = 0;
		for(flow::EntityPair& pair: entities2) {
			if(pair.entity->get_name() == "test1") how_much_found++;
			if(pair.entity->get_name() == "test3") how_much_found++;
			if(pair.entity->get_name() == "test5") how_much_found++;
		}
		EXPECT( (how_much_found == entities2.size()) );
	} catch(flow::exception::EntityFindByGroup& e) {
		EXPECT(false);
	}
	EXPECT_THROWS( (entity_collector.get_by_group("g3").size() > 0) );
},
CASE("EntityCollector add, get_by_name, size and remove_by_name works correctly."){
	flow::EntityCollector entity_collector;
	//creating some sample tests entities.
	entity_collector.add( std::make_shared<TestEntity>("test1") );
	entity_collector.add( std::make_shared<TestEntity>("test2") );
	entity_collector.add( std::make_shared<TestEntity>("test3") );

	try{
		//expecting some simple questions to be answered as true. test1 should exist and have its name and test2 should do the same.
		EXPECT( (entity_collector.get_by_name("test1")->get_name() == "test1") );
		EXPECT( (entity_collector.get_by_name("test2")->get_name() == "test2") );
		EXPECT( (entity_collector.get_by_name("test3")->get_name() == "test3") );
		EXPECT(entity_collector.size() == 3); // entire entity list should also be 2 items in size.
	} catch(flow::exception::EntityFindByName& e) {
		EXPECT(false); // if the questions are answered false then the test fails. If the get_by_name method doesn't find any entity then it should throw an exception.
	}
	
	EXPECT_NO_THROW( entity_collector.remove_by_name("test3") );

	EXPECT_THROWS( (entity_collector.get_by_name("test3")->get_name() == "test3") ); // expect it to throw because test3 doesn't exist.
},
CASE("EntityCollector add, get_by_group, size and remove_by_group works correctly."){
	flow::EntityCollector entity_collector;
	//creating some sample tests entities. First parameter is entity name and second is group name.
	entity_collector.add( std::make_shared<TestEntity>("test1", "g1") );
	entity_collector.add( std::make_shared<TestEntity>("test2", "g2") );
	entity_collector.add( std::make_shared<TestEntity>("test3", "g1") );
	entity_collector.add( std::make_shared<TestEntity>("test4", "g2") );
	entity_collector.add( std::make_shared<TestEntity>("test5", "g1") );
	try{
		//expecting some simple questions to be answered as true.
		flow::EntityMap entities = entity_collector.get_by_group("g2");
		EXPECT(entities.size() == 2);
		int how_much_found = 0;
		for(flow::EntityPair& pair: entities) {
			if(pair.entity->get_name() == "test2") how_much_found++;
			if(pair.entity->get_name() == "test4") how_much_found++;
		}
		EXPECT( (how_much_found == entities.size()) );

		flow::EntityMap entities2 = entity_collector.get_by_group("g1");
		EXPECT(entities2.size() == 3);
		how_much_found = 0;
		for(flow::EntityPair& pair: entities2) {
			if(pair.entity->get_name() == "test1") how_much_found++;
			if(pair.entity->get_name() == "test3") how_much_found++;
			if(pair.entity->get_name() == "test5") how_much_found++;
		}
		EXPECT( (how_much_found == entities2.size()) );
	} catch(flow::exception::EntityFindByGroup& e) {
		EXPECT(false);
	}

	EXPECT_NO_THROW( entity_collector.remove_by_group("g1") );
	EXPECT_THROWS( (entity_collector.get_by_group("g1").size() > 0) );
	EXPECT_THROWS( entity_collector.remove_by_group("g1") );

	try {
		//expecting some simple questions to be answered as true.
		flow::EntityMap entities = entity_collector.get_by_group("g2");
		EXPECT(entities.size() == 2);
		int how_much_found = 0;
		for(flow::EntityPair& pair: entities) {
			if(pair.entity->get_name() == "test2") how_much_found++;
			if(pair.entity->get_name() == "test4") how_much_found++;
		}
		EXPECT( (how_much_found == entities.size()) );
	} catch(flow::exception::EntityFindByGroup& e) {
		EXPECT(false);
	}

	EXPECT_THROWS( (entity_collector.get_by_group("g3").size() > 0) );
},