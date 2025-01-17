#pragma once

#include <functional>

#include "DummySaiInterface.h"

class MockableSaiInterface: public saimeta::DummySaiInterface
{
    public:

        MockableSaiInterface();

        virtual ~MockableSaiInterface();

    public:

        virtual sai_status_t initialize(
                _In_ uint64_t flags,
                _In_ const sai_service_method_table_t *service_method_table) override;
        virtual sai_status_t uninitialize(void) override;

    public: // SAI interface overrides

        virtual sai_status_t create(
                _In_ sai_object_type_t objectType,
                _Out_ sai_object_id_t* objectId,
                _In_ sai_object_id_t switchId,
                _In_ uint32_t attr_count,
                _In_ const sai_attribute_t *attr_list) override;

        std::function<sai_status_t(sai_object_type_t, _Out_ sai_object_id_t*, sai_object_id_t, uint32_t, const sai_attribute_t*)> mock_create;

        virtual sai_status_t remove(
                _In_ sai_object_type_t objectType,
                _In_ sai_object_id_t objectId) override;

        std::function<sai_status_t(sai_object_type_t, sai_object_id_t)> mock_remove;

        virtual sai_status_t set(
                _In_ sai_object_type_t objectType,
                _In_ sai_object_id_t objectId,
                _In_ const sai_attribute_t *attr) override;

        std::function<sai_status_t(sai_object_type_t, sai_object_id_t, const sai_attribute_t *)> mock_set;

        virtual sai_status_t get(
                _In_ sai_object_type_t objectType,
                _In_ sai_object_id_t objectId,
                _In_ uint32_t attr_count,
                _Inout_ sai_attribute_t *attr_list) override;

        std::function<sai_status_t(sai_object_type_t, sai_object_id_t, uint32_t, sai_attribute_t *)> mock_get;

    public: // bulk QUAD oid

        virtual sai_status_t bulkCreate(
                _In_ sai_object_type_t object_type,
                _In_ sai_object_id_t switch_id,
                _In_ uint32_t object_count,
                _In_ const uint32_t *attr_count,
                _In_ const sai_attribute_t **attr_list,
                _In_ sai_bulk_op_error_mode_t mode,
                _Out_ sai_object_id_t *object_id,
                _Out_ sai_status_t *object_statuses) override;

        std::function<sai_status_t(sai_object_type_t, sai_object_id_t, uint32_t, const uint32_t *, const sai_attribute_t **, sai_bulk_op_error_mode_t, sai_object_id_t *, sai_status_t*)> mock_bulkCreate;

        virtual sai_status_t bulkRemove(
                _In_ sai_object_type_t object_type,
                _In_ uint32_t object_count,
                _In_ const sai_object_id_t *object_id,
                _In_ sai_bulk_op_error_mode_t mode,
                _Out_ sai_status_t *object_statuses) override;

        std::function<sai_status_t(sai_object_type_t, uint32_t, const sai_object_id_t *, sai_bulk_op_error_mode_t, sai_status_t *)> mock_bulkRemove;

        virtual sai_status_t bulkSet(
                _In_ sai_object_type_t object_type,
                _In_ uint32_t object_count,
                _In_ const sai_object_id_t *object_id,
                _In_ const sai_attribute_t *attr_list,
                _In_ sai_bulk_op_error_mode_t mode,
                _Out_ sai_status_t *object_statuses) override;

        std::function<sai_status_t(sai_object_type_t, uint32_t, const sai_object_id_t *, const sai_attribute_t *, sai_bulk_op_error_mode_t, sai_status_t *)> mock_bulkSet;

    public: // stats API

        virtual sai_status_t getStats(
                _In_ sai_object_type_t object_type,
                _In_ sai_object_id_t object_id,
                _In_ uint32_t number_of_counters,
                _In_ const sai_stat_id_t *counter_ids,
                _Out_ uint64_t *counters) override;

        std::function<sai_status_t(sai_object_type_t, sai_object_id_t, uint32_t, const sai_stat_id_t *, uint64_t *)> mock_getStats;

        virtual sai_status_t queryStatsCapability(
                _In_ sai_object_id_t switch_id,
                _In_ sai_object_type_t object_type,
                _Inout_ sai_stat_capability_list_t *stats_capability) override;

        std::function<sai_status_t(sai_object_id_t, sai_object_type_t, sai_stat_capability_list_t *)> mock_queryStatsCapability;

        virtual sai_status_t getStatsExt(
                _In_ sai_object_type_t object_type,
                _In_ sai_object_id_t object_id,
                _In_ uint32_t number_of_counters,
                _In_ const sai_stat_id_t *counter_ids,
                _In_ sai_stats_mode_t mode,
                _Out_ uint64_t *counters) override;

        std::function<sai_status_t(sai_object_type_t, sai_object_id_t, uint32_t, const sai_stat_id_t *, sai_stats_mode_t, uint64_t *)> mock_getStatsExt;

        virtual sai_status_t clearStats(
                _In_ sai_object_type_t object_type,
                _In_ sai_object_id_t object_id,
                _In_ uint32_t number_of_counters,
                _In_ const sai_stat_id_t *counter_ids) override;

        std::function<sai_status_t(sai_object_type_t, sai_object_id_t, uint32_t, const sai_stat_id_t *)> mock_clearStats;


    public: // non QUAD API

        virtual sai_status_t flushFdbEntries(
                _In_ sai_object_id_t switchId,
                _In_ uint32_t attrCount,
                _In_ const sai_attribute_t *attrList) override;

        std::function<sai_status_t(sai_object_id_t, uint32_t, const sai_attribute_t *)> mock_flushFdbEntries;

    public: // SAI API

        virtual sai_status_t objectTypeGetAvailability(
                _In_ sai_object_id_t switchId,
                _In_ sai_object_type_t objectType,
                _In_ uint32_t attrCount,
                _In_ const sai_attribute_t *attrList,
                _Out_ uint64_t *count) override;

        std::function<sai_status_t(sai_object_id_t, sai_object_type_t, uint32_t, const sai_attribute_t *, uint64_t *)> mock_objectTypeGetAvailability;


        virtual sai_status_t queryAttributeCapability(
                _In_ sai_object_id_t switch_id,
                _In_ sai_object_type_t object_type,
                _In_ sai_attr_id_t attr_id,
                _Out_ sai_attr_capability_t *capability) override;

        std::function<sai_status_t(sai_object_id_t, sai_object_type_t, sai_attr_id_t, sai_attr_capability_t *)> mock_queryAttributeCapability;


        virtual sai_status_t queryAattributeEnumValuesCapability(
                _In_ sai_object_id_t switch_id,
                _In_ sai_object_type_t object_type,
                _In_ sai_attr_id_t attr_id,
                _Inout_ sai_s32_list_t *enum_values_capability) override;

        std::function<sai_status_t(sai_object_id_t, sai_object_type_t, sai_attr_id_t, sai_s32_list_t *)> mock_queryAattributeEnumValuesCapability;

        virtual sai_object_type_t objectTypeQuery(
                _In_ sai_object_id_t objectId) override;

        std::function<sai_object_type_t(sai_object_id_t)> mock_objectTypeQuery;


        virtual sai_object_id_t switchIdQuery(
                _In_ sai_object_id_t objectId) override;

        std::function<sai_object_id_t(sai_object_id_t)> mock_switchIdQuery;

        virtual sai_status_t logSet(
                _In_ sai_api_t api,
                _In_ sai_log_level_t log_level) override;

        std::function<sai_status_t(sai_api_t, sai_log_level_t)> mock_logSet;
};
