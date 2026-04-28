function type_anotations()
    local types = darwin.dtw.list_files_recursively("types",true)
    local type_file_contents = {}
    for i=1,#types do
       local content = types[i] 
       table.insert(type_file_contents,darwin.dtw.load_file(content))
    end
    darwin.dtw.write_file("release/types.lua",table.concat(type_file_contents,""))
end

darwin.add_recipe({
    name="types",   
    description="Build type Annotations",
    outs={"release/types.lua"},
    inputs={ "types"},
    callback= type_anotations
})