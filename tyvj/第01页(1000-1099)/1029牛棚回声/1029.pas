var
  s1,s2:ansistring;
  i,ans:longint;
begin
  readln(s1);
  readln(s2);
  ans:=0;
  for i:=1 to length(s1) do
    if i<=length(s2) then
      if (copy(s1,1,i)=copy(s2,length(s2)-i+1,i)) and (ans<i) then ans:=i;
  for i:=1 to length(s2) do
    if i<=length(s1) then
      if (copy(s2,1,i)=copy(s1,length(s1)-i+1,i)) and (ans<i) then ans:=i;
  writeln(ans);
end.