const
 BigPrime=3214567;
 MaxStep=6;
type
 pointer=^rec;
 rec=record
      v,step:longint;
      next:pointer;
     end;
var
 total:longint;
 hash:array[0..BigPrime-1]of pointer;
 q:array[1..400000]of rec;
function update(a:longint;p:longint):longint;
begin
 a:=a xor (1 shl p);
 if p mod 5<>0 then a:=a xor (1 shl (p-1));
 if (p+1) mod 5<>0 then a:=a xor (1 shl (p+1));
 if p<20 then a:=a xor (1 shl (p+5));
 if p>4 then a:=a xor (1 shl (p-5));
 exit(a);
end;
function find(a:longint;step:longint):boolean;
var
 now:pointer;
begin
 now:=hash[a mod BigPrime];
 while now<>nil do
  begin
   if now^.v=a then exit(true);
   now:=now^.next;
  end;
 new(now);
 now^.v:=a;
 now^.step:=step;
 now^.next:=hash[a mod BigPrime];
 hash[a mod BigPrime]:=now;
 total:=total+1;
 exit(false);
end;
procedure solve;
var
 p:longint;
 close:longint=0;
 open:longint=1;
begin
 find(1 shl 25-1,0);
 q[1].v:=1 shl 25-1;
 q[1].step:=0;
 repeat
  inc(close);
  for p:=0 to 24 do
   if not find(update(q[close].v,p),q[close].step+1) and
   (q[close].step+1<MaxStep) then
   begin
    open:=open+1;
    q[open].v:=update(q[close].v,p);
    q[open].step:=q[close].step+1;
   end;
 until close>=open;
end;
procedure print(a:longint);
var
 now:pointer;
begin
 now:=hash[a mod BigPrime];
 while now<>nil do
  begin
   if now^.v=a then
    begin
     writeln(now^.step);
     exit;
    end;
   now:=now^.next;
  end;
 writeln(-1);
end;
procedure main;
var
 ch:char;
 i,j,n,t:longint;
begin
 readln(n);
 for i:=1 to n do
  begin
   t:=0;
   for j:=1 to 25 do
    begin
     read(ch);
     t:=t*2+ord(ch)-48;
     if j mod 5=0 then readln;
    end;
   print(t);
   if i<n then readln;
  end;
end;
begin
 solve;
 main;
end.
