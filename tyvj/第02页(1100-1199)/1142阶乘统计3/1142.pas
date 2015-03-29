var
  n,ans:int64;
begin
  readln(n);ans:=0;
  while n>1 do
    begin
      ans:=ans+n div 5;
      n:=n div 5;
    end;
  writeln(ans);
end.