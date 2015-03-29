var
  s:string;
  x,ans,i:longint;
begin
  while true do
    begin
      readln(s);
      if s='0' then break;
      x:=0;
      ans:=0;
      for i:=length(s) downto 1 do
        begin
          x:=x shl 1+1;
          ans:=ans+x*(ord(s[i])-48);
        end;
      writeln(ans);
    end;
end.