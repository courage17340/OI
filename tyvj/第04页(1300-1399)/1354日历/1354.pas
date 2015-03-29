var
  ans,yy,i,p:longint;
function yes(y:longint):boolean;
begin
  if y mod 100=0 then if y mod 400=0 then exit(true);
  if y mod 100>0 then if y mod 4=0 then exit(true);
  exit(false);
end;
begin
  ans:=0;p:=5;
  readln(yy);
  for i:=2010 downto yy+1 do
    begin
      p:=p-31;while p<=0 do inc(p,7);if p=5 then inc(ans);{11.30}
      p:=p-31;while p<=0 do inc(p,7);if p=5 then inc(ans);{10.30}
      p:=p-30;while p<=0 do inc(p,7);if p=5 then inc(ans);{9.30}
      p:=p-31;while p<=0 do inc(p,7);if p=5 then inc(ans);{8.30}
      p:=p-31;while p<=0 do inc(p,7);if p=5 then inc(ans);{7.30}
      p:=p-30;while p<=0 do inc(p,7);if p=5 then inc(ans);{6.30}
      p:=p-31;while p<=0 do inc(p,7);if p=5 then inc(ans);{5.30}
      p:=p-30;while p<=0 do inc(p,7);if p=5 then inc(ans);{4.30}
      p:=p-31;while p<=0 do inc(p,7);if p=5 then inc(ans);{3.30}
      p:=p-30;if yes(i) then dec(p);while p<=0 do inc(p,7);{2.28}
      p:=p-29;while p<=0 do inc(p,7);if p=5 then inc(ans);{1.30}
      p:=p-31;while p<=0 do inc(p,7);if (p=5)and(i<>yy+1) then inc(ans);{12.30}
      inc(p);
    end;
  writeln(ans);
end.
