function filter(props)

local acoes = get_json ("acoes.json")

   if acoes == nil then

       return false

   end

local downloaddoprocesso = acoes.download_processo

  if downloaddoprocesso.realizada == true then

  return false

 end

  if downloaddoprocesso.tentativas > 4 then

  return false

   end

return true

end